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
			printf("����ʧ��\n");
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

	//���ļ��е��Ѿ����ڵ�ͨѶ¼����Ϣ���ص�ͨѶ¼��
	LoadContact(ps);
}

void AddContact(struct Contact* ps)
{
	int ret = CheckCapacity(ps);//�����޸ĵ�ǰͨѶ¼������
	if (ret == 1)
	{
		printf("����������:");
		scanf("%s", &ps->data[ps->size].name);
		printf("����������:");
		scanf("%d", &ps->data[ps->size].age);
		printf("�������Ա�:");
		scanf("%s", &ps->data[ps->size].sex);
		printf("������绰:");
		scanf("%s", &ps->data[ps->size].tele);
		printf("�������ַ:");
		scanf("%s", &ps->data[ps->size].addr);

		++(ps->size);
		printf("��ӳɹ�\n");
	}
}

void DelContact(struct Contact* ps)
{
	int pos = 0;
	char name[MAX_NAME] = {0};
	printf("�������ɾ���˵�����:");
	scanf("%s", name);
	pos = FindbyName(ps, name);//�����������ڵ�Ԫ�ص��±�
	if (pos == -1)
	{
		printf("��ɾ���ĳ�Ա������\n");
	}
	else
	{
		for (int j = pos; j < ps->size-1; ++j)
		{
			ps->data[j] = ps->data[j + 1];
		}
		--(ps->size);
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	printf("������������˵�����:");
	scanf("%s", name);
	pos = FindbyName(ps, name);
	if (pos == -1)
	{
		printf("�����ҵ��˲�����\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-15s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("��������޸��˵�����:");
	scanf("%s", name);
	int pos = FindbyName(ps, name);
	if (pos == -1)
	{
		printf("���޸ĵ��˲�����\n");
	}
	else
	{
		printf("��������������:");
		scanf("%s", ps->data[pos].name);
		printf("��������������:");
		scanf("%d", &ps->data[pos].age);
		printf("�����������Ա�:");
		scanf("%s", ps->data[pos].sex);
		printf("����������绰:");
		scanf("%s", ps->data[pos].tele);
		printf("�����������ַ:");
		scanf("%s", ps->data[pos].addr);
		printf("�޸����\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-15s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	//��ͨѶ¼�е�����д���ļ���
	for (int i = 0; i < ps->size; ++i)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfwrite);
	}

	fclose(pfwrite);
	pfwrite = NULL;
}