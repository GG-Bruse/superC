#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

static int FindbyName(const struct Contact* ps, char name[MAX_NAME])
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

int CheckCapacity(struct Contact* ps);

void LoadContact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.txt", "r");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}

	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		++(ps->size);
	}
	
	fclose(pfRead);
	pfRead = NULL;
}

int CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* pnew = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (pnew != NULL)
		{
			ps->data = pnew;
			ps->capacity += 2;
			return 1;
		}
		else
		{
			printf("增容失败\n");
			return 0;
		}
	}
	return 1;
}

void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;

	//把文件中的已经存在的通讯录的信息加载到通讯录中
	LoadContact(ps);
}

void AddContact(struct Contact* ps)
{
	int ret = CheckCapacity(ps);//检测或修改当前通讯录的容量
	if (ret == 1)
	{
		printf("请输入姓名:");
		scanf("%s", &ps->data[ps->size].name);
		printf("请输入年龄:");
		scanf("%d", &ps->data[ps->size].age);
		printf("请输入性别:");
		scanf("%s", &ps->data[ps->size].sex);
		printf("请输入电话:");
		scanf("%s", &ps->data[ps->size].tele);
		printf("请输入地址:");
		scanf("%s", &ps->data[ps->size].addr);

		++(ps->size);
		printf("添加成功\n");
	}
}

void DelContact(struct Contact* ps)
{
	int pos = 0;
	char name[MAX_NAME] = {0};
	printf("请输入待删除人的姓名:");
	scanf("%s", name);
	pos = FindbyName(ps, name);//返回名字所在的元素的下标
	if (pos == -1)
	{
		printf("待删除的成员不存在\n");
	}
	else
	{
		for (int j = pos; j < ps->size-1; ++j)
		{
			ps->data[j] = ps->data[j + 1];
		}
		--(ps->size);
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	printf("请输入待查找人的姓名:");
	scanf("%s", name);
	pos = FindbyName(ps, name);
	if (pos == -1)
	{
		printf("待查找的人不存在\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-15s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-15s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入待修改人的姓名:");
	scanf("%s", name);
	int pos = FindbyName(ps, name);
	if (pos == -1)
	{
		printf("待修改的人不存在\n");
	}
	else
	{
		printf("请重新输入姓名:");
		scanf("%s", ps->data[pos].name);
		printf("请重新输入年龄:");
		scanf("%d", &ps->data[pos].age);
		printf("请重新输入性别:");
		scanf("%s", ps->data[pos].sex);
		printf("请重新输入电话:");
		scanf("%s", ps->data[pos].tele);
		printf("请重新输入地址:");
		scanf("%s", ps->data[pos].addr);
		printf("修改完成\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-15s\n", "名字", "年龄", "性别", "电话", "地址");
		for (int i = 0; i < ps->size; ++i)
		{
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-15s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

void DestroyContact(struct Contact* ps)
{
	if (ps != NULL)
	{
		free(ps->data);
		ps->data = NULL;
	}
}

void SaveContact(struct Contact* ps)
{
	FILE* pfwrite = fopen("contact.txt", "w");
	if (pfwrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	//将通讯录中的数据写到文件中
	for (int i = 0; i < ps->size; ++i)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfwrite);
	}

	fclose(pfwrite);
	pfwrite = NULL;
}