// vector standard header

// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once
#ifndef _VECTOR_
#define _VECTOR_
#include <yvals_core.h>
#if _STL_COMPILER_PREPROCESSOR
#include <xmemory>

#if _HAS_CXX17
#include <xpolymorphic_allocator.h>
#endif // _HAS_CXX17

#pragma pack(push, _CRT_PACKING)
#pragma warning(push, _STL_WARNING_LEVEL)
#pragma warning(disable : _STL_DISABLED_WARNINGS)
_STL_DISABLE_CLANG_WARNINGS
#pragma push_macro("new")
#undef new

_STD_BEGIN
// CLASS TEMPLATE _Vector_const_iterator
template <class _Myvec>
class _Vector_const_iterator : public _Iterator_base {
public:
#ifdef __cpp_lib_concepts
    using iterator_concept = contiguous_iterator_tag;
#endif // __cpp_lib_concepts
    using iterator_category = random_access_iterator_tag;
    using value_type        = typename _Myvec::value_type;
    using difference_type   = typename _Myvec::difference_type;
    using pointer           = typename _Myvec::const_pointer;
    using reference         = const value_type&;

    using _Tptr = typename _Myvec::pointer;

    _CONSTEXPR20_CONTAINER _Vector_const_iterator() noexcept : _Ptr() {}

    _CONSTEXPR20_CONTAINER _Vector_const_iterator(_Tptr _Parg, const _Container_base* _Pvector) noexcept : _Ptr(_Parg) {
        this->_Adopt(_Pvector);
    }

    // TRANSITION, DevCom-1331017
    _CONSTEXPR20_CONTAINER _Vector_const_iterator& operator=(const _Vector_const_iterator&) noexcept = default;

    _NODISCARD _CONSTEXPR20_CONTAINER reference operator*() const noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(_Ptr, "can't dereference value-initialized vector iterator");
        _STL_VERIFY(
            _Mycont->_Myfirst <= _Ptr && _Ptr < _Mycont->_Mylast, "can't dereference out of range vector iterator");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return *_Ptr;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER pointer operator->() const noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(_Ptr, "can't dereference value-initialized vector iterator");
        _STL_VERIFY(
            _Mycont->_Myfirst <= _Ptr && _Ptr < _Mycont->_Mylast, "can't dereference out of range vector iterator");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return _Ptr;
    }

    _CONSTEXPR20_CONTAINER _Vector_const_iterator& operator++() noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(_Ptr, "can't increment value-initialized vector iterator");
        _STL_VERIFY(_Ptr < _Mycont->_Mylast, "can't increment vector iterator past end");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        ++_Ptr;
        return *this;
    }

    _CONSTEXPR20_CONTAINER _Vector_const_iterator operator++(int) noexcept {
        _Vector_const_iterator _Tmp = *this;
        ++*this;
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vector_const_iterator& operator--() noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(_Ptr, "can't decrement value-initialized vector iterator");
        _STL_VERIFY(_Mycont->_Myfirst < _Ptr, "can't decrement vector iterator before begin");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        --_Ptr;
        return *this;
    }

    _CONSTEXPR20_CONTAINER _Vector_const_iterator operator--(int) noexcept {
        _Vector_const_iterator _Tmp = *this;
        --*this;
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER void _Verify_offset(const difference_type _Off) const noexcept {
#if _ITERATOR_DEBUG_LEVEL == 0
        (void) _Off;
#else // ^^^ _ITERATOR_DEBUG_LEVEL == 0 ^^^ // vvv _ITERATOR_DEBUG_LEVEL != 0 vvv
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(_Off == 0 || _Ptr, "cannot seek value-initialized vector iterator");
        if (_Off < 0) {
            _STL_VERIFY(_Off >= _Mycont->_Myfirst - _Ptr, "cannot seek vector iterator before begin");
        }

        if (_Off > 0) {
            _STL_VERIFY(_Off <= _Mycont->_Mylast - _Ptr, "cannot seek vector iterator after end");
        }
#endif // _ITERATOR_DEBUG_LEVEL == 0
    }

    _CONSTEXPR20_CONTAINER _Vector_const_iterator& operator+=(const difference_type _Off) noexcept {
        _Verify_offset(_Off);
        _Ptr += _Off;
        return *this;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Vector_const_iterator operator+(const difference_type _Off) const noexcept {
        _Vector_const_iterator _Tmp = *this;
        _Tmp += _Off; // TRANSITION, LLVM-49342
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vector_const_iterator& operator-=(const difference_type _Off) noexcept {
        return *this += -_Off;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Vector_const_iterator operator-(const difference_type _Off) const noexcept {
        _Vector_const_iterator _Tmp = *this;
        _Tmp -= _Off; // TRANSITION, LLVM-49342
        return _Tmp;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER difference_type operator-(const _Vector_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Ptr - _Right._Ptr;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reference operator[](const difference_type _Off) const noexcept {
        return *(*this + _Off);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER bool operator==(const _Vector_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Ptr == _Right._Ptr;
    }

#if _HAS_CXX20
    _NODISCARD _CONSTEXPR20_CONTAINER strong_ordering operator<=>(const _Vector_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Unfancy(_Ptr) <=> _Unfancy(_Right._Ptr);
    }
#else // ^^^ _HAS_CXX20 ^^^ / vvv !_HAS_CXX20 vvv
    _NODISCARD bool operator!=(const _Vector_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }

    _NODISCARD bool operator<(const _Vector_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Ptr < _Right._Ptr;
    }

    _NODISCARD bool operator>(const _Vector_const_iterator& _Right) const noexcept {
        return _Right < *this;
    }

    _NODISCARD bool operator<=(const _Vector_const_iterator& _Right) const noexcept {
        return !(_Right < *this);
    }

    _NODISCARD bool operator>=(const _Vector_const_iterator& _Right) const noexcept {
        return !(*this < _Right);
    }
#endif // !_HAS_CXX20

    _CONSTEXPR20_CONTAINER void _Compat(const _Vector_const_iterator& _Right) const noexcept {
        // test for compatible iterator pair
#if _ITERATOR_DEBUG_LEVEL == 0
        (void) _Right;
#else // ^^^ _ITERATOR_DEBUG_LEVEL == 0 ^^^ // vvv _ITERATOR_DEBUG_LEVEL != 0 vvv
        _STL_VERIFY(this->_Getcont() == _Right._Getcont(), "vector iterators incompatible");
#endif // _ITERATOR_DEBUG_LEVEL == 0
    }

#if _ITERATOR_DEBUG_LEVEL != 0
    friend _CONSTEXPR20_CONTAINER void _Verify_range(
        const _Vector_const_iterator& _First, const _Vector_const_iterator& _Last) noexcept {
        _STL_VERIFY(_First._Getcont() == _Last._Getcont(), "vector iterators in range are from different containers");
        _STL_VERIFY(_First._Ptr <= _Last._Ptr, "vector iterator range transposed");
    }
#endif // _ITERATOR_DEBUG_LEVEL != 0

    using _Prevent_inheriting_unwrap = _Vector_const_iterator;

    _NODISCARD _CONSTEXPR20_CONTAINER const value_type* _Unwrapped() const noexcept {
        return _Unfancy(_Ptr);
    }

    _CONSTEXPR20_CONTAINER void _Seek_to(const value_type* _It) noexcept {
        _Ptr = _Refancy<_Tptr>(const_cast<value_type*>(_It));
    }

    _Tptr _Ptr; // pointer to element in vector
};

template <class _Myvec>
_NODISCARD _CONSTEXPR20_CONTAINER _Vector_const_iterator<_Myvec> operator+(
    typename _Vector_const_iterator<_Myvec>::difference_type _Off, _Vector_const_iterator<_Myvec> _Next) noexcept {
    return _Next += _Off;
}

#if _HAS_CXX20
template <class _Myvec>
struct pointer_traits<_Vector_const_iterator<_Myvec>> {
    using pointer         = _Vector_const_iterator<_Myvec>;
    using element_type    = const typename pointer::value_type;
    using difference_type = typename pointer::difference_type;

    _NODISCARD static constexpr element_type* to_address(const pointer _Iter) noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        // A value-initialized iterator is in the domain of to_address. An invalidated end iterator for a vector with
        // capacity() of 0 is not. This function cannot distinguish those two cases, so it incorrectly does not diagnose
        // the latter. In practice, this isn't a significant problem since to_address returns nullptr for such an
        // iterator.
        const auto _Mycont = static_cast<const _Myvec*>(_Iter._Getcont());
        if (_Mycont) {
            _STL_VERIFY(_Mycont->_Myfirst <= _Iter._Ptr && _Iter._Ptr <= _Mycont->_Mylast,
                "can't convert out-of-range vector iterator to pointer");
        } else {
            _STL_VERIFY(!_Iter._Ptr, "can't convert invalid vector iterator to pointer");
        }
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return _STD to_address(_Iter._Ptr);
    }
};
#endif // _HAS_CXX20

// CLASS TEMPLATE _Vector_iterator
template <class _Myvec>
class _Vector_iterator : public _Vector_const_iterator<_Myvec> {
public:
    using _Mybase = _Vector_const_iterator<_Myvec>;

#ifdef __cpp_lib_concepts
    using iterator_concept = contiguous_iterator_tag;
#endif // __cpp_lib_concepts
    using iterator_category = random_access_iterator_tag;
    using value_type        = typename _Myvec::value_type;
    using difference_type   = typename _Myvec::difference_type;
    using pointer           = typename _Myvec::pointer;
    using reference         = value_type&;

    using _Mybase::_Mybase;

    // TRANSITION, DevCom-1331017
    _CONSTEXPR20_CONTAINER _Vector_iterator& operator=(const _Vector_iterator&) noexcept = default;

    _NODISCARD _CONSTEXPR20_CONTAINER reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD _CONSTEXPR20_CONTAINER pointer operator->() const noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(this->_Ptr, "can't dereference value-initialized vector iterator");
        _STL_VERIFY(_Mycont->_Myfirst <= this->_Ptr && this->_Ptr < _Mycont->_Mylast,
            "can't dereference out of range vector iterator");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return this->_Ptr;
    }

    _CONSTEXPR20_CONTAINER _Vector_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _CONSTEXPR20_CONTAINER _Vector_iterator operator++(int) noexcept {
        _Vector_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vector_iterator& operator--() noexcept {
        _Mybase::operator--();
        return *this;
    }

    _CONSTEXPR20_CONTAINER _Vector_iterator operator--(int) noexcept {
        _Vector_iterator _Tmp = *this;
        _Mybase::operator--();
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vector_iterator& operator+=(const difference_type _Off) noexcept {
        _Mybase::operator+=(_Off);
        return *this;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Vector_iterator operator+(const difference_type _Off) const noexcept {
        _Vector_iterator _Tmp = *this;
        _Tmp += _Off; // TRANSITION, LLVM-49342
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vector_iterator& operator-=(const difference_type _Off) noexcept {
        _Mybase::operator-=(_Off);
        return *this;
    }

    using _Mybase::operator-;

    _NODISCARD _CONSTEXPR20_CONTAINER _Vector_iterator operator-(const difference_type _Off) const noexcept {
        _Vector_iterator _Tmp = *this;
        _Tmp -= _Off; // TRANSITION, LLVM-49342
        return _Tmp;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reference operator[](const difference_type _Off) const noexcept {
        return const_cast<reference>(_Mybase::operator[](_Off));
    }

    using _Prevent_inheriting_unwrap = _Vector_iterator;

    _NODISCARD _CONSTEXPR20_CONTAINER value_type* _Unwrapped() const noexcept {
        return _Unfancy(this->_Ptr);
    }
};

template <class _Myvec>
_NODISCARD _CONSTEXPR20_CONTAINER _Vector_iterator<_Myvec> operator+(
    typename _Vector_iterator<_Myvec>::difference_type _Off, _Vector_iterator<_Myvec> _Next) noexcept {
    return _Next += _Off;
}

#if _HAS_CXX20
template <class _Myvec>
struct pointer_traits<_Vector_iterator<_Myvec>> {
    using pointer         = _Vector_iterator<_Myvec>;
    using element_type    = typename pointer::value_type;
    using difference_type = typename pointer::difference_type;

    _NODISCARD static constexpr element_type* to_address(const pointer _Iter) noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        // A value-initialized iterator is in the domain of to_address. An invalidated end iterator for a vector with
        // capacity() of 0 is not. This function cannot distinguish those two cases, so it incorrectly does not diagnose
        // the latter. In practice, this isn't a significant problem since to_address returns nullptr for such an
        // iterator.
        const auto _Mycont = static_cast<const _Myvec*>(_Iter._Getcont());
        if (_Mycont) {
            _STL_VERIFY(_Mycont->_Myfirst <= _Iter._Ptr && _Iter._Ptr <= _Mycont->_Mylast,
                "can't convert out-of-range vector iterator to pointer");
        } else {
            _STL_VERIFY(!_Iter._Ptr, "can't convert invalid vector iterator to pointer");
        }
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return _STD to_address(_Iter._Ptr);
    }
};
#endif // _HAS_CXX20

// vector TYPE WRAPPERS
template <class _Value_type, class _Size_type, class _Difference_type, class _Pointer, class _Const_pointer,
    class _Reference, class _Const_reference>
struct _Vec_iter_types {
    using value_type      = _Value_type;
    using size_type       = _Size_type;
    using difference_type = _Difference_type;
    using pointer         = _Pointer;
    using const_pointer   = _Const_pointer;
};

// STRUCT _Value_init_tag
struct _Value_init_tag { // tag to request value-initialization
    explicit _Value_init_tag() = default;
};

// CLASS TEMPLATE _Vector_val
template <class _Val_types>
class _Vector_val : public _Container_base {
public:
    using value_type      = typename _Val_types::value_type;
    using size_type       = typename _Val_types::size_type;
    using difference_type = typename _Val_types::difference_type;
    using pointer         = typename _Val_types::pointer;
    using const_pointer   = typename _Val_types::const_pointer;
    using reference       = value_type&;
    using const_reference = const value_type&;

    _CONSTEXPR20_CONTAINER _Vector_val() noexcept : _Myfirst(), _Mylast(), _Myend() {}

    _CONSTEXPR20_CONTAINER _Vector_val(pointer _First, pointer _Last, pointer _End) noexcept
        : _Myfirst(_First), _Mylast(_Last), _Myend(_End) {}

    _CONSTEXPR20_CONTAINER void _Swap_val(_Vector_val& _Right) noexcept {
        this->_Swap_proxy_and_iterators(_Right);
        _Swap_adl(_Myfirst, _Right._Myfirst);
        _Swap_adl(_Mylast, _Right._Mylast);
        _Swap_adl(_Myend, _Right._Myend);
    }

    _CONSTEXPR20_CONTAINER void _Take_contents(_Vector_val& _Right) noexcept {
        this->_Swap_proxy_and_iterators(_Right);
        _Myfirst = _Right._Myfirst;
        _Mylast  = _Right._Mylast;
        _Myend   = _Right._Myend;

        _Right._Myfirst = nullptr;
        _Right._Mylast  = nullptr;
        _Right._Myend   = nullptr;
    }

    pointer _Myfirst; // pointer to beginning of array
    pointer _Mylast; // pointer to current end of sequence
    pointer _Myend; // pointer to end of array
};

// FUNCTION TEMPLATE _Unfancy_maybe_null
template <class _Ptrty>
constexpr auto _Unfancy_maybe_null(_Ptrty _Ptr) noexcept {
    // converts from a (potentially null) fancy pointer to a plain pointer
    return _Ptr ? _STD addressof(*_Ptr) : nullptr;
}

template <class _Ty>
constexpr _Ty* _Unfancy_maybe_null(_Ty* _Ptr) noexcept { // do nothing for plain pointers
    return _Ptr;
}

// CLASS TEMPLATE vector
template <class _Ty, class _Alloc = allocator<_Ty>>
class vector { // varying size array of values
private:
    template <class>
    friend class _Vb_val;
    friend _Tidy_guard<vector>;

    using _Alty        = _Rebind_alloc_t<_Alloc, _Ty>;
    using _Alty_traits = allocator_traits<_Alty>;

public:
    static_assert(!_ENFORCE_MATCHING_ALLOCATORS || is_same_v<_Ty, typename _Alloc::value_type>,
        _MISMATCHED_ALLOCATOR_MESSAGE("vector<T, Allocator>", "T"));

    using value_type      = _Ty;
    using allocator_type  = _Alloc;
    using pointer         = typename _Alty_traits::pointer;
    using const_pointer   = typename _Alty_traits::const_pointer;
    using reference       = _Ty&;
    using const_reference = const _Ty&;
    using size_type       = typename _Alty_traits::size_type;
    using difference_type = typename _Alty_traits::difference_type;

private:
    using _Scary_val = _Vector_val<conditional_t<_Is_simple_alloc_v<_Alty>, _Simple_types<_Ty>,
        _Vec_iter_types<_Ty, size_type, difference_type, pointer, const_pointer, _Ty&, const _Ty&>>>;

public:
    using iterator               = _Vector_iterator<_Scary_val>;
    using const_iterator         = _Vector_const_iterator<_Scary_val>;
    using reverse_iterator       = _STD reverse_iterator<iterator>;
    using const_reverse_iterator = _STD reverse_iterator<const_iterator>;

    _CONSTEXPR20_CONTAINER vector() noexcept(is_nothrow_default_constructible_v<_Alty>)
        : _Mypair(_Zero_then_variadic_args_t{}) {
        _Mypair._Myval2._Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alty, _Getal()));
    }

    _CONSTEXPR20_CONTAINER explicit vector(const _Alloc& _Al) noexcept : _Mypair(_One_then_variadic_args_t{}, _Al) {
        _Mypair._Myval2._Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alty, _Getal()));
    }

private:
    template <class _Ty2>
    _CONSTEXPR20_CONTAINER void _Construct_n_copies_of_ty(_CRT_GUARDOVERFLOW const size_type _Count, const _Ty2& _Val) {
        auto&& _Alproxy = _GET_PROXY_ALLOCATOR(_Alty, _Getal());
        auto& _My_data  = _Mypair._Myval2;
        _Container_proxy_ptr<_Alty> _Proxy(_Alproxy, _My_data);
        if (_Count != 0) {
            _Buy_nonzero(_Count);
            _Tidy_guard<vector> _Guard{this};
            _My_data._Mylast = _Ufill(_My_data._Myfirst, _Count, _Val);
            _Guard._Target   = nullptr;
        }

        _Proxy._Release();
    }

public:
    _CONSTEXPR20_CONTAINER explicit vector(_CRT_GUARDOVERFLOW const size_type _Count, const _Alloc& _Al = _Alloc())
        : _Mypair(_One_then_variadic_args_t{}, _Al) {
        _Construct_n_copies_of_ty(_Count, _Value_init_tag{});
    }

    _CONSTEXPR20_CONTAINER vector(
        _CRT_GUARDOVERFLOW const size_type _Count, const _Ty& _Val, const _Alloc& _Al = _Alloc())
        : _Mypair(_One_then_variadic_args_t{}, _Al) {
        _Construct_n_copies_of_ty(_Count, _Val);
    }

private:
    template <class _Iter>
    _CONSTEXPR20_CONTAINER void _Range_construct_or_tidy(_Iter _First, _Iter _Last, input_iterator_tag) {
        _Tidy_guard<vector> _Guard{this};
        for (; _First != _Last; ++_First) {
            emplace_back(*_First); // performance note: emplace_back()'s strong guarantee is unnecessary here
        }

        _Guard._Target = nullptr;
    }

    template <class _Iter>
    _CONSTEXPR20_CONTAINER void _Range_construct_or_tidy(_Iter _First, _Iter _Last, forward_iterator_tag) {
        const auto _Count = _Convert_size<size_type>(static_cast<size_t>(_STD distance(_First, _Last)));
        if (_Count != 0) {
            _Buy_nonzero(_Count);
            _Tidy_guard<vector> _Guard{this};
            auto& _My_data   = _Mypair._Myval2;
            _My_data._Mylast = _Ucopy(_First, _Last, _My_data._Myfirst);
            _Guard._Target   = nullptr;
        }
    }

public:
    template <class _Iter, enable_if_t<_Is_iterator_v<_Iter>, int> = 0>
    _CONSTEXPR20_CONTAINER vector(_Iter _First, _Iter _Last, const _Alloc& _Al = _Alloc())
        : _Mypair(_One_then_variadic_args_t{}, _Al) {
        auto&& _Alproxy = _GET_PROXY_ALLOCATOR(_Alty, _Getal());
        _Container_proxy_ptr<_Alty> _Proxy(_Alproxy, _Mypair._Myval2);
        _Adl_verify_range(_First, _Last);
        _Range_construct_or_tidy(_Get_unwrapped(_First), _Get_unwrapped(_Last), _Iter_cat_t<_Iter>{});
        _Proxy._Release();
    }

    _CONSTEXPR20_CONTAINER vector(initializer_list<_Ty> _Ilist, const _Alloc& _Al = _Alloc())
        : _Mypair(_One_then_variadic_args_t{}, _Al) {
        auto&& _Alproxy = _GET_PROXY_ALLOCATOR(_Alty, _Getal());
        _Container_proxy_ptr<_Alty> _Proxy(_Alproxy, _Mypair._Myval2);
        _Range_construct_or_tidy(_Ilist.begin(), _Ilist.end(), random_access_iterator_tag{});
        _Proxy._Release();
    }

    _CONSTEXPR20_CONTAINER vector(const vector& _Right)
        : _Mypair(_One_then_variadic_args_t{}, _Alty_traits::select_on_container_copy_construction(_Right._Getal())) {
        auto&& _Alproxy           = _GET_PROXY_ALLOCATOR(_Alty, _Getal());
        auto& _My_data            = _Mypair._Myval2;
        const auto& _Right_data   = _Right._Mypair._Myval2;
        const pointer _Rightfirst = _Right_data._Myfirst;
        const pointer _Rightlast  = _Right_data._Mylast;
        _Container_proxy_ptr<_Alty> _Proxy(_Alproxy, _My_data);
        if (_Rightfirst != _Rightlast) {
            _Buy_raw(static_cast<size_type>(_Rightlast - _Rightfirst));
            _Tidy_guard<vector> _Guard{this};
            _My_data._Mylast = _Ucopy(_Rightfirst, _Rightlast, _My_data._Myfirst);
            _Guard._Target   = nullptr;
        }

        _Proxy._Release();
    }

    _CONSTEXPR20_CONTAINER vector(const vector& _Right, const _Alloc& _Al) : _Mypair(_One_then_variadic_args_t{}, _Al) {
        auto&& _Alproxy           = _GET_PROXY_ALLOCATOR(_Alty, _Getal());
        auto& _My_data            = _Mypair._Myval2;
        const auto& _Right_data   = _Right._Mypair._Myval2;
        const pointer _Rightfirst = _Right_data._Myfirst;
        const pointer _Rightlast  = _Right_data._Mylast;
        _Container_proxy_ptr<_Alty> _Proxy(_Alproxy, _My_data);
        if (_Rightfirst != _Rightlast) {
            _Buy_raw(static_cast<size_type>(_Rightlast - _Rightfirst));
            _Tidy_guard<vector> _Guard{this};
            _My_data._Mylast = _Ucopy(_Rightfirst, _Rightlast, _My_data._Myfirst);
            _Guard._Target   = nullptr;
        }

        _Proxy._Release();
    }

private:
    _CONSTEXPR20_CONTAINER void _Move_construct(vector& _Right, true_type) noexcept {
        // move from _Right, stealing its contents
        _Mypair._Myval2._Take_contents(_Right._Mypair._Myval2);
    }

    _CONSTEXPR20_CONTAINER void _Move_construct(vector& _Right, false_type) {
        // move from _Right, possibly moving its contents
        if constexpr (!_Alty_traits::is_always_equal::value) {
            if (_Getal() != _Right._Getal()) {
                const auto& _Right_data   = _Right._Mypair._Myval2;
                const pointer _Rightfirst = _Right_data._Myfirst;
                const pointer _Rightlast  = _Right_data._Mylast;
                if (_Rightfirst != _Rightlast) {
                    _Buy_raw(static_cast<size_type>(_Rightlast - _Rightfirst));
                    _Tidy_guard<vector> _Guard{this};
                    auto& _My_data   = _Mypair._Myval2;
                    _My_data._Mylast = _Umove(_Rightfirst, _Rightlast, _My_data._Myfirst);
                    _Guard._Target   = nullptr;
                }
                return;
            }
        }

        _Move_construct(_Right, true_type{});
    }

public:
    _CONSTEXPR20_CONTAINER vector(vector&& _Right) noexcept
        : _Mypair(_One_then_variadic_args_t{}, _STD move(_Right._Getal()),
            _STD exchange(_Right._Mypair._Myval2._Myfirst, nullptr),
            _STD exchange(_Right._Mypair._Myval2._Mylast, nullptr),
            _STD exchange(_Right._Mypair._Myval2._Myend, nullptr)) {
        _Mypair._Myval2._Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alty, _Getal()));
        _Mypair._Myval2._Swap_proxy_and_iterators(_Right._Mypair._Myval2);
    }

    _CONSTEXPR20_CONTAINER vector(vector&& _Right, const _Alloc& _Al) noexcept(
        _Alty_traits::is_always_equal::value) // strengthened
        : _Mypair(_One_then_variadic_args_t{}, _Al) {
        auto&& _Alproxy = _GET_PROXY_ALLOCATOR(_Alty, _Getal());
        _Container_proxy_ptr<_Alty> _Proxy(_Alproxy, _Mypair._Myval2);
        _Move_construct(_Right, typename _Alty_traits::is_always_equal::type{});
        _Proxy._Release();
    }

private:
    _CONSTEXPR20_CONTAINER void _Move_assign(vector& _Right, _Equal_allocators) noexcept {
        _Tidy();
        _Pocma(_Getal(), _Right._Getal());
        _Mypair._Myval2._Take_contents(_Right._Mypair._Myval2);
    }

    _CONSTEXPR20_CONTAINER void _Move_assign(vector& _Right, _Propagate_allocators) noexcept /* terminates */ {
        _Tidy();
#if _ITERATOR_DEBUG_LEVEL != 0
        if (_Getal() != _Right._Getal()) {
            // intentionally slams into noexcept on OOM, TRANSITION, VSO-466800
            _Mypair._Myval2._Reload_proxy(
                _GET_PROXY_ALLOCATOR(_Alty, _Getal()), _GET_PROXY_ALLOCATOR(_Alty, _Right._Getal()));
        }
#endif

        _Pocma(_Getal(), _Right._Getal());
        _Mypair._Myval2._Take_contents(_Right._Mypair._Myval2);
    }

    _CONSTEXPR20_CONTAINER void _Move_assign(vector& _Right, _No_propagate_allocators) {
        if (_Getal() == _Right._Getal()) {
            _Move_assign(_Right, _Equal_allocators{});
        } else {
            auto& _Right_data    = _Right._Mypair._Myval2;
            const pointer _First = _Right_data._Myfirst;
            const pointer _Last  = _Right_data._Mylast;
            const auto _Newsize  = static_cast<size_type>(_Last - _First);

            auto& _My_data    = _Mypair._Myval2;
            pointer& _Myfirst = _My_data._Myfirst;
            pointer& _Mylast  = _My_data._Mylast;

            _My_data._Orphan_all();

            const auto _Oldcapacity = static_cast<size_type>(_My_data._Myend - _Myfirst);
            if constexpr (conjunction_v<bool_constant<_Ptr_copy_cat<_Ty*, _Ty*>::_Trivially_copyable>,
                              _Uses_default_construct<_Alty, _Ty*, _Ty>, _Uses_default_destroy<_Alty, _Ty*>>) {
                if (_Newsize > _Oldcapacity) {
                    _Clear_and_reserve_geometric(_Newsize);
                }

                _Mylast = _Refancy<pointer>(_Copy_memmove(_Unfancy(_First), _Unfancy(_Last), _Unfancy(_Myfirst)));
            } else {
                auto _Oldsize = static_cast<size_type>(_Mylast - _Myfirst);

                if (_Newsize > _Oldsize) {
                    if (_Newsize > _Oldcapacity) { // reallocate
                        _Clear_and_reserve_geometric(_Newsize);
                        _Oldsize = 0;
                    }

                    const pointer _Mid = _First + _Oldsize;
                    _Move_unchecked(_First, _Mid, _Myfirst);
                    _Mylast = _Umove(_Mid, _Last, _Mylast);
                } else {
                    const pointer _Newlast = _Myfirst + _Newsize;
                    _Move_unchecked(_First, _Last, _Myfirst);
                    _Destroy(_Newlast, _Mylast);
                    _Mylast = _Newlast;
                }
            }
        }
    }

public:
    _CONSTEXPR20_CONTAINER vector& operator=(vector&& _Right) noexcept(
        noexcept(_Move_assign(_Right, _Choose_pocma<_Alty>{}))) {
        if (this != _STD addressof(_Right)) {
            _Move_assign(_Right, _Choose_pocma<_Alty>{});
        }

        return *this;
    }

    _CONSTEXPR20_CONTAINER ~vector() noexcept {
        _Tidy();
#if _ITERATOR_DEBUG_LEVEL != 0
        auto&& _Alproxy = _GET_PROXY_ALLOCATOR(_Alty, _Getal());
        _Delete_plain_internal(_Alproxy, _STD exchange(_Mypair._Myval2._Myproxy, nullptr));
#endif // _ITERATOR_DEBUG_LEVEL != 0
    }

private:
    template <class... _Valty>
    _CONSTEXPR20_CONTAINER decltype(auto) _Emplace_back_with_unused_capacity(_Valty&&... _Val) {
        // insert by perfectly forwarding into element at end, provide strong guarantee
        auto& _My_data   = _Mypair._Myval2;
        pointer& _Mylast = _My_data._Mylast;
        _STL_INTERNAL_CHECK(_Mylast != _My_data._Myend); // check that we have unused capacity
        _Alty_traits::construct(_Getal(), _Unfancy(_Mylast), _STD forward<_Valty>(_Val)...);
        _Orphan_range(_Mylast, _Mylast);
        _Ty& _Result = *_Mylast;
        ++_Mylast;
#if _HAS_CXX17
        return _Result;
#else // ^^^ _HAS_CXX17 ^^^ // vvv !_HAS_CXX17 vvv
        (void) _Result;
#endif // _HAS_CXX17
    }

public:
    template <class... _Valty>
    _CONSTEXPR20_CONTAINER decltype(auto) emplace_back(_Valty&&... _Val) {
        // insert by perfectly forwarding into element at end, provide strong guarantee
        auto& _My_data   = _Mypair._Myval2;
        pointer& _Mylast = _My_data._Mylast;
        if (_Mylast != _My_data._Myend) {
            return _Emplace_back_with_unused_capacity(_STD forward<_Valty>(_Val)...);
        }

        _Ty& _Result = *_Emplace_reallocate(_Mylast, _STD forward<_Valty>(_Val)...);
#if _HAS_CXX17
        return _Result;
#else // ^^^ _HAS_CXX17 ^^^ // vvv !_HAS_CXX17 vvv
        (void) _Result;
#endif // _HAS_CXX17
    }

    _CONSTEXPR20_CONTAINER void push_back(const _Ty& _Val) { // insert element at end, provide strong guarantee
        emplace_back(_Val);
    }

    _CONSTEXPR20_CONTAINER void push_back(_Ty&& _Val) {
        // insert by moving into element at end, provide strong guarantee
        emplace_back(_STD move(_Val));
    }

    template <class... _Valty>
    _CONSTEXPR20_CONTAINER pointer _Emplace_reallocate(const pointer _Whereptr, _Valty&&... _Val) {
        // reallocate and insert by perfectly forwarding _Val at _Whereptr
        _Alty& _Al        = _Getal();
        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;

        _STL_INTERNAL_CHECK(_Mylast == _My_data._Myend); // check that we have no unused capacity

        const auto _Whereoff = static_cast<size_type>(_Whereptr - _Myfirst);
        const auto _Oldsize  = static_cast<size_type>(_Mylast - _Myfirst);

        if (_Oldsize == max_size()) {
            _Xlength();
        }

        const size_type _Newsize     = _Oldsize + 1;
        const size_type _Newcapacity = _Calculate_growth(_Newsize);

        const pointer _Newvec           = _Al.allocate(_Newcapacity);
        const pointer _Constructed_last = _Newvec + _Whereoff + 1;
        pointer _Constructed_first      = _Constructed_last;

        _TRY_BEGIN
        _Alty_traits::construct(_Al, _Unfancy(_Newvec + _Whereoff), _STD forward<_Valty>(_Val)...);
        _Constructed_first = _Newvec + _Whereoff;

        if (_Whereptr == _Mylast) { // at back, provide strong guarantee
            _Umove_if_noexcept(_Myfirst, _Mylast, _Newvec);
        } else { // provide basic guarantee
            _Umove(_Myfirst, _Whereptr, _Newvec);
            _Constructed_first = _Newvec;
            _Umove(_Whereptr, _Mylast, _Newvec + _Whereoff + 1);
        }
        _CATCH_ALL
        _Destroy(_Constructed_first, _Constructed_last);
        _Al.deallocate(_Newvec, _Newcapacity);
        _RERAISE;
        _CATCH_END

        _Change_array(_Newvec, _Newsize, _Newcapacity);
        return _Newvec + _Whereoff;
    }

    template <class... _Valty>
    _CONSTEXPR20_CONTAINER iterator emplace(const_iterator _Where, _Valty&&... _Val) {
        // insert by perfectly forwarding _Val at _Where
        const pointer _Whereptr = _Where._Ptr;
        auto& _My_data          = _Mypair._Myval2;
        const pointer _Oldlast  = _My_data._Mylast;
#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(
            _Where._Getcont() == _STD addressof(_My_data) && _Whereptr >= _My_data._Myfirst && _Oldlast >= _Whereptr,
            "vector emplace iterator outside range");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        if (_Oldlast != _My_data._Myend) {
            if (_Whereptr == _Oldlast) { // at back, provide strong guarantee
                _Emplace_back_with_unused_capacity(_STD forward<_Valty>(_Val)...);
            } else {
                auto& _Al = _Getal();
                _Alloc_temporary<_Alty> _Obj(_Al, _STD forward<_Valty>(_Val)...); // handle aliasing
                // after constructing _Obj, provide basic guarantee
                _Orphan_range(_Whereptr, _Oldlast);
                _Alty_traits::construct(_Al, _Unfancy(_Oldlast), _STD move(_Oldlast[-1]));
                ++_My_data._Mylast;
                _Move_backward_unchecked(_Whereptr, _Oldlast - 1, _Oldlast);
                *_Whereptr = _STD move(_Obj._Storage._Value);
            }

            return _Make_iterator(_Whereptr);
        }

        return _Make_iterator(_Emplace_reallocate(_Whereptr, _STD forward<_Valty>(_Val)...));
    }

    _CONSTEXPR20_CONTAINER iterator insert(const_iterator _Where, const _Ty& _Val) { // insert _Val at _Where
        return emplace(_Where, _Val);
    }

    _CONSTEXPR20_CONTAINER iterator insert(const_iterator _Where, _Ty&& _Val) { // insert by moving _Val at _Where
        return emplace(_Where, _STD move(_Val));
    }

    _CONSTEXPR20_CONTAINER iterator insert(
        const_iterator _Where, _CRT_GUARDOVERFLOW const size_type _Count, const _Ty& _Val) {
        // insert _Count * _Val at _Where
        const pointer _Whereptr = _Where._Ptr;

        auto& _My_data   = _Mypair._Myval2;
        pointer& _Mylast = _My_data._Mylast;

        const pointer _Oldfirst = _My_data._Myfirst;
        const pointer _Oldlast  = _Mylast;
#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(_Where._Getcont() == _STD addressof(_My_data) && _Whereptr >= _Oldfirst && _Oldlast >= _Whereptr,
            "vector insert iterator outside range");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        const auto _Whereoff        = static_cast<size_type>(_Whereptr - _Oldfirst);
        const auto _Unused_capacity = static_cast<size_type>(_My_data._Myend - _Oldlast);
        const bool _One_at_back     = _Count == 1 && _Whereptr == _Oldlast;
        if (_Count == 0) { // nothing to do, avoid invalidating iterators
        } else if (_Count > _Unused_capacity) { // reallocate
            const auto _Oldsize = static_cast<size_type>(_Oldlast - _Oldfirst);

            if (_Count > max_size() - _Oldsize) {
                _Xlength();
            }

            const size_type _Newsize     = _Oldsize + _Count;
            const size_type _Newcapacity = _Calculate_growth(_Newsize);

            const pointer _Newvec           = _Getal().allocate(_Newcapacity);
            const pointer _Constructed_last = _Newvec + _Whereoff + _Count;
            pointer _Constructed_first      = _Constructed_last;

            _TRY_BEGIN
            _Ufill(_Newvec + _Whereoff, _Count, _Val);
            _Constructed_first = _Newvec + _Whereoff;

            if (_One_at_back) { // provide strong guarantee
                _Umove_if_noexcept(_Oldfirst, _Oldlast, _Newvec);
            } else { // provide basic guarantee
                _Umove(_Oldfirst, _Whereptr, _Newvec);
                _Constructed_first = _Newvec;
                _Umove(_Whereptr, _Oldlast, _Newvec + _Whereoff + _Count);
            }
            _CATCH_ALL
            _Destroy(_Constructed_first, _Constructed_last);
            _Getal().deallocate(_Newvec, _Newcapacity);
            _RERAISE;
            _CATCH_END

            _Change_array(_Newvec, _Newsize, _Newcapacity);
        } else if (_One_at_back) { // provide strong guarantee
            _Emplace_back_with_unused_capacity(_Val);
        } else { // provide basic guarantee
            const _Alloc_temporary<_Alty> _Tmp_storage(_Getal(), _Val); // handle aliasing
            const auto& _Tmp              = _Tmp_storage._Storage._Value;
            const auto _Affected_elements = static_cast<size_type>(_Oldlast - _Whereptr);
            _Orphan_range(_Whereptr, _Oldlast);

            if (_Count > _Affected_elements) { // new stuff spills off end
                _Mylast = _Ufill(_Oldlast, _Count - _Affected_elements, _Tmp);
                _Mylast = _Umove(_Whereptr, _Oldlast, _Mylast);
                _STD fill(_Whereptr, _Oldlast, _Tmp);
            } else { // new stuff can all be assigned
                _Mylast = _Umove(_Oldlast - _Count, _Oldlast, _Oldlast);
                _Move_backward_unchecked(_Whereptr, _Oldlast - _Count, _Oldlast);
                _STD fill(_Whereptr, _Whereptr + _Count, _Tmp);
            }
        }

        return _Make_iterator_offset(_Whereoff);
    }

private:
    template <class _Iter>
    _CONSTEXPR20_CONTAINER void _Insert_range(const_iterator _Where, _Iter _First, _Iter _Last, input_iterator_tag) {
        // insert input range [_First, _Last) at _Where
        if (_First == _Last) {
            return; // nothing to do, avoid invalidating iterators
        }

        auto& _My_data       = _Mypair._Myval2;
        pointer& _Myfirst    = _My_data._Myfirst;
        pointer& _Mylast     = _My_data._Mylast;
        const auto _Whereoff = static_cast<size_type>(_Where._Ptr - _Myfirst);
        const auto _Oldsize  = static_cast<size_type>(_Mylast - _Myfirst);

        // For one-at-back, provide strong guarantee.
        // Otherwise, provide basic guarantee (despite N4659 26.3.11.5 [vector.modifiers]/1).
        // Performance note: except for one-at-back, emplace_back()'s strong guarantee is unnecessary here.

        for (; _First != _Last; ++_First) {
            emplace_back(*_First);
        }

        _Orphan_range(_Myfirst + _Whereoff, _Myfirst + _Oldsize);

        _STD rotate(_Myfirst + _Whereoff, _Myfirst + _Oldsize, _Mylast);
    }

    template <class _Iter>
    _CONSTEXPR20_CONTAINER void _Insert_range(const_iterator _Where, _Iter _First, _Iter _Last, forward_iterator_tag) {
        // insert forward range [_First, _Last) at _Where
        const pointer _Whereptr = _Where._Ptr;
        const auto _Count       = _Convert_size<size_type>(static_cast<size_t>(_STD distance(_First, _Last)));

        auto& _My_data   = _Mypair._Myval2;
        pointer& _Mylast = _My_data._Mylast;

        const pointer _Oldfirst     = _My_data._Myfirst;
        const pointer _Oldlast      = _Mylast;
        const auto _Unused_capacity = static_cast<size_type>(_My_data._Myend - _Oldlast);

        if (_Count == 0) { // nothing to do, avoid invalidating iterators
        } else if (_Count > _Unused_capacity) { // reallocate
            const auto _Oldsize = static_cast<size_type>(_Oldlast - _Oldfirst);

            if (_Count > max_size() - _Oldsize) {
                _Xlength();
            }

            const size_type _Newsize     = _Oldsize + _Count;
            const size_type _Newcapacity = _Calculate_growth(_Newsize);

            const pointer _Newvec           = _Getal().allocate(_Newcapacity);
            const auto _Whereoff            = static_cast<size_type>(_Whereptr - _Oldfirst);
            const pointer _Constructed_last = _Newvec + _Whereoff + _Count;
            pointer _Constructed_first      = _Constructed_last;

            _TRY_BEGIN
            _Ucopy(_First, _Last, _Newvec + _Whereoff);
            _Constructed_first = _Newvec + _Whereoff;

            if (_Count == 1 && _Whereptr == _Oldlast) { // one at back, provide strong guarantee
                _Umove_if_noexcept(_Oldfirst, _Oldlast, _Newvec);
            } else { // provide basic guarantee
                _Umove(_Oldfirst, _Whereptr, _Newvec);
                _Constructed_first = _Newvec;
                _Umove(_Whereptr, _Oldlast, _Newvec + _Whereoff + _Count);
            }
            _CATCH_ALL
            _Destroy(_Constructed_first, _Constructed_last);
            _Getal().deallocate(_Newvec, _Newcapacity);
            _RERAISE;
            _CATCH_END

            _Change_array(_Newvec, _Newsize, _Newcapacity);
        } else { // Attempt to provide the strong guarantee for EmplaceConstructible failure.
                 // If we encounter copy/move construction/assignment failure, provide the basic guarantee.
                 // (For one-at-back, this provides the strong guarantee.)

            const auto _Affected_elements = static_cast<size_type>(_Oldlast - _Whereptr);

            if (_Count < _Affected_elements) { // some affected elements must be assigned
                _Mylast = _Umove(_Oldlast - _Count, _Oldlast, _Oldlast);
                _Move_backward_unchecked(_Whereptr, _Oldlast - _Count, _Oldlast);
                _Destroy(_Whereptr, _Whereptr + _Count);

                _TRY_BEGIN
                _Ucopy(_First, _Last, _Whereptr);
                _CATCH_ALL
                // glue the broken pieces back together

                _TRY_BEGIN
                _Umove(_Whereptr + _Count, _Whereptr + 2 * _Count, _Whereptr);
                _CATCH_ALL
                // vaporize the detached piece
                _Orphan_range(_Whereptr, _Oldlast);
                _Destroy(_Whereptr + _Count, _Mylast);
                _Mylast = _Whereptr;
                _RERAISE;
                _CATCH_END

                _Move_unchecked(_Whereptr + 2 * _Count, _Mylast, _Whereptr + _Count);
                _Destroy(_Oldlast, _Mylast);
                _Mylast = _Oldlast;
                _RERAISE;
                _CATCH_END
            } else { // affected elements don't overlap before/after
                const pointer _Relocated = _Whereptr + _Count;
                _Mylast                  = _Umove(_Whereptr, _Oldlast, _Relocated);
                _Destroy(_Whereptr, _Oldlast);

                _TRY_BEGIN
                _Ucopy(_First, _Last, _Whereptr);
                _CATCH_ALL
                // glue the broken pieces back together

                _TRY_BEGIN
                _Umove(_Relocated, _Mylast, _Whereptr);
                _CATCH_ALL
                // vaporize the detached piece
                _Orphan_range(_Whereptr, _Oldlast);
                _Destroy(_Relocated, _Mylast);
                _Mylast = _Whereptr;
                _RERAISE;
                _CATCH_END

                _Destroy(_Relocated, _Mylast);
                _Mylast = _Oldlast;
                _RERAISE;
                _CATCH_END
            }

            _Orphan_range(_Whereptr, _Oldlast);
        }
    }

public:
    template <class _Iter, enable_if_t<_Is_iterator_v<_Iter>, int> = 0>
    _CONSTEXPR20_CONTAINER iterator insert(const_iterator _Where, _Iter _First, _Iter _Last) {
        const pointer _Whereptr = _Where._Ptr;
        auto& _My_data          = _Mypair._Myval2;
        const pointer _Oldfirst = _My_data._Myfirst;
#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(
            _Where._Getcont() == _STD addressof(_My_data) && _Whereptr >= _Oldfirst && _My_data._Mylast >= _Whereptr,
            "vector insert iterator outside range");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        _Adl_verify_range(_First, _Last);
        const auto _Whereoff = static_cast<size_type>(_Whereptr - _Oldfirst);
        _Insert_range(_Where, _Get_unwrapped(_First), _Get_unwrapped(_Last), _Iter_cat_t<_Iter>{});
        return _Make_iterator_offset(_Whereoff);
    }

    _CONSTEXPR20_CONTAINER iterator insert(const_iterator _Where, initializer_list<_Ty> _Ilist) {
        return insert(_Where, _Ilist.begin(), _Ilist.end());
    }

    _CONSTEXPR20_CONTAINER void assign(_CRT_GUARDOVERFLOW const size_type _Newsize, const _Ty& _Val) {
        // assign _Newsize * _Val
        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;

        _My_data._Orphan_all();

        auto _Oldsize = static_cast<size_type>(_Mylast - _Myfirst);
        if (_Newsize > _Oldsize) {
            const auto _Oldcapacity = static_cast<size_type>(_My_data._Myend - _Myfirst);
            if (_Newsize > _Oldcapacity) { // reallocate
                _Clear_and_reserve_geometric(_Newsize);
                _Oldsize = 0;
            } else {
                _STD fill(_Myfirst, _Mylast, _Val);
            }

            _Mylast = _Ufill(_Mylast, _Newsize - _Oldsize, _Val);
        } else {
            const pointer _Newlast = _Myfirst + _Newsize;
            _STD fill(_Myfirst, _Newlast, _Val);
            _Destroy(_Newlast, _Mylast);
            _Mylast = _Newlast;
        }
    }

private:
    template <class _Iter>
    _CONSTEXPR20_CONTAINER void _Assign_range(_Iter _First, _Iter _Last, input_iterator_tag) {
        // assign input range [_First, _Last)
        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;

        _My_data._Orphan_all();

        pointer _Next = _Myfirst;

        for (; _First != _Last && _Next != _Mylast; ++_First, (void) ++_Next) {
            *_Next = *_First;
        }

        // Code size optimization: we've exhausted only the source, only the dest, or both.
        // If we've exhausted only the source: we Trim, then Append does nothing.
        // If we've exhausted only the dest: Trim does nothing, then we Append.
        // If we've exhausted both: Trim does nothing, then Append does nothing.

        // Trim.
        _Destroy(_Next, _Mylast);
        _Mylast = _Next;

        // Append.
        for (; _First != _Last; ++_First) {
            emplace_back(*_First); // performance note: emplace_back()'s strong guarantee is unnecessary here
        }
    }

    template <class _Iter>
    _CONSTEXPR20_CONTAINER void _Assign_range(_Iter _First, _Iter _Last, forward_iterator_tag) {
        // assign forward range [_First, _Last)
        const auto _Newsize = _Convert_size<size_type>(static_cast<size_t>(_STD distance(_First, _Last)));
        auto& _My_data      = _Mypair._Myval2;
        pointer& _Myfirst   = _My_data._Myfirst;
        pointer& _Mylast    = _My_data._Mylast;
        pointer& _Myend     = _My_data._Myend;

        _My_data._Orphan_all();

        if constexpr (conjunction_v<bool_constant<_Ptr_copy_cat<_Iter, _Ty*>::_Trivially_copyable>,
                          _Uses_default_construct<_Alty, _Ty*, decltype(*_First)>,
                          _Uses_default_destroy<_Alty, _Ty*>>) {
#ifdef __cpp_lib_constexpr_dynamic_alloc
            if (!_STD is_constant_evaluated())
#endif // __cpp_lib_constexpr_dynamic_alloc
            {
                const auto _Oldcapacity = static_cast<size_type>(_Myend - _Myfirst);
                if (_Newsize > _Oldcapacity) {
                    _Clear_and_reserve_geometric(_Newsize);
                }

                _Mylast = _Refancy<pointer>(_Copy_memmove(_First, _Last, _Unfancy(_Myfirst)));
                return;
            }
        }
        auto _Oldsize = static_cast<size_type>(_Mylast - _Myfirst);

        if (_Newsize > _Oldsize) {
            const auto _Oldcapacity = static_cast<size_type>(_Myend - _Myfirst);
            if (_Newsize > _Oldcapacity) { // reallocate
                _Clear_and_reserve_geometric(_Newsize);
                _Oldsize = 0;
            }

            // performance note: traversing [_First, _Mid) twice
            const _Iter _Mid = _STD next(_First, static_cast<difference_type>(_Oldsize));
            _Copy_unchecked(_First, _Mid, _Myfirst);
            _Mylast = _Ucopy(_Mid, _Last, _Mylast);
        } else {
            const pointer _Newlast = _Myfirst + _Newsize;
            _Copy_unchecked(_First, _Last, _Myfirst);
            _Destroy(_Newlast, _Mylast);
            _Mylast = _Newlast;
        }
    }

public:
    template <class _Iter, enable_if_t<_Is_iterator_v<_Iter>, int> = 0>
    _CONSTEXPR20_CONTAINER void assign(_Iter _First, _Iter _Last) {
        _Adl_verify_range(_First, _Last);
        _Assign_range(_Get_unwrapped(_First), _Get_unwrapped(_Last), _Iter_cat_t<_Iter>{});
    }

    _CONSTEXPR20_CONTAINER void assign(initializer_list<_Ty> _Ilist) {
        _Assign_range(_Ilist.begin(), _Ilist.end(), random_access_iterator_tag{});
    }

private:
    _CONSTEXPR20_CONTAINER void _Copy_assign(const vector& _Right, false_type) {
        _Pocca(_Getal(), _Right._Getal());
        auto& _Right_data = _Right._Mypair._Myval2;
        assign(_Right_data._Myfirst, _Right_data._Mylast);
    }

    _CONSTEXPR20_CONTAINER void _Copy_assign(const vector& _Right, true_type) {
        if (_Getal() != _Right._Getal()) {
            _Tidy();
            _Mypair._Myval2._Reload_proxy(
                _GET_PROXY_ALLOCATOR(_Alty, _Getal()), _GET_PROXY_ALLOCATOR(_Alty, _Right._Getal()));
        }

        _Copy_assign(_Right, false_type{});
    }

public:
    _CONSTEXPR20_CONTAINER vector& operator=(const vector& _Right) {
        if (this != _STD addressof(_Right)) {
            _Copy_assign(_Right, _Choose_pocca<_Alty>{});
        }

        return *this;
    }

    _CONSTEXPR20_CONTAINER vector& operator=(initializer_list<_Ty> _Ilist) {
        _Assign_range(_Ilist.begin(), _Ilist.end(), random_access_iterator_tag{});
        return *this;
    }

private:
    template <class _Ty2>
    _CONSTEXPR20_CONTAINER void _Resize_reallocate(const size_type _Newsize, const _Ty2& _Val) {
        if (_Newsize > max_size()) {
            _Xlength();
        }

        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;

        const auto _Oldsize          = static_cast<size_type>(_Mylast - _Myfirst);
        const size_type _Newcapacity = _Calculate_growth(_Newsize);

        const pointer _Newvec         = _Getal().allocate(_Newcapacity);
        const pointer _Appended_first = _Newvec + _Oldsize;
        pointer _Appended_last        = _Appended_first;

        _TRY_BEGIN
        _Appended_last = _Ufill(_Appended_first, _Newsize - _Oldsize, _Val);
        _Umove_if_noexcept(_Myfirst, _Mylast, _Newvec);
        _CATCH_ALL
        _Destroy(_Appended_first, _Appended_last);
        _Getal().deallocate(_Newvec, _Newcapacity);
        _RERAISE;
        _CATCH_END

        _Change_array(_Newvec, _Newsize, _Newcapacity);
    }

    template <class _Ty2>
    _CONSTEXPR20_CONTAINER void _Resize(const size_type _Newsize, const _Ty2& _Val) {
        // trim or append elements, provide strong guarantee
        auto& _My_data      = _Mypair._Myval2;
        pointer& _Myfirst   = _My_data._Myfirst;
        pointer& _Mylast    = _My_data._Mylast;
        const auto _Oldsize = static_cast<size_type>(_Mylast - _Myfirst);
        if (_Newsize < _Oldsize) { // trim
            const pointer _Newlast = _Myfirst + _Newsize;
            _Orphan_range(_Newlast, _Mylast);
            _Destroy(_Newlast, _Mylast);
            _Mylast = _Newlast;
            return;
        }

        if (_Newsize > _Oldsize) { // append
            const auto _Oldcapacity = static_cast<size_type>(_My_data._Myend - _Myfirst);
            if (_Newsize > _Oldcapacity) { // reallocate
                _Resize_reallocate(_Newsize, _Val);
                return;
            }

            const pointer _Oldlast = _Mylast;
            _Mylast                = _Ufill(_Oldlast, _Newsize - _Oldsize, _Val);
            _Orphan_range(_Oldlast, _Oldlast);
        }

        // if _Newsize == _Oldsize, do nothing; avoid invalidating iterators
    }

public:
    _CONSTEXPR20_CONTAINER void resize(_CRT_GUARDOVERFLOW const size_type _Newsize) {
        // trim or append value-initialized elements, provide strong guarantee
        _Resize(_Newsize, _Value_init_tag{});
    }

    _CONSTEXPR20_CONTAINER void resize(_CRT_GUARDOVERFLOW const size_type _Newsize, const _Ty& _Val) {
        // trim or append copies of _Val, provide strong guarantee
        _Resize(_Newsize, _Val);
    }

private:
    _CONSTEXPR20_CONTAINER void _Reallocate_exactly(const size_type _Newcapacity) {
        // set capacity to _Newcapacity (without geometric growth), provide strong guarantee
        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;

        const auto _Size = static_cast<size_type>(_Mylast - _Myfirst);

        const pointer _Newvec = _Getal().allocate(_Newcapacity);

        _TRY_BEGIN
        _Umove_if_noexcept(_Myfirst, _Mylast, _Newvec);
        _CATCH_ALL
        _Getal().deallocate(_Newvec, _Newcapacity);
        _RERAISE;
        _CATCH_END

        _Change_array(_Newvec, _Size, _Newcapacity);
    }

#if _ITERATOR_DEBUG_LEVEL != 0 && defined(_ENABLE_STL_INTERNAL_CHECK)
    void _Check_all_orphaned_locked() const noexcept {
        _Lockit _Lock(_LOCK_DEBUG);
        auto& _My_data = _Mypair._Myval2;
        _STL_INTERNAL_CHECK(!_My_data._Myproxy->_Myfirstiter);
    }

    _CONSTEXPR20_CONTAINER void _Check_all_orphaned() const noexcept {
#ifdef __cpp_lib_constexpr_dynamic_alloc
        if (_STD is_constant_evaluated()) {
            auto& _My_data = _Mypair._Myval2;
            _STL_INTERNAL_CHECK(!_My_data._Myproxy->_Myfirstiter);
        } else
#endif // __cpp_lib_constexpr_dynamic_alloc
        {
            _Check_all_orphaned_locked();
        }
    }
#endif // _ITERATOR_DEBUG_LEVEL != 0 && defined(_ENABLE_STL_INTERNAL_CHECK)

    _CONSTEXPR20_CONTAINER void _Clear_and_reserve_geometric(const size_type _Newsize) {
        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;
        pointer& _Myend   = _My_data._Myend;

#if _ITERATOR_DEBUG_LEVEL != 0 && defined(_ENABLE_STL_INTERNAL_CHECK)
        _STL_INTERNAL_CHECK(_Newsize != 0);
        _Check_all_orphaned();
#endif // _ITERATOR_DEBUG_LEVEL != 0 && defined(_ENABLE_STL_INTERNAL_CHECK)

        if (_Newsize > max_size()) {
            _Xlength();
        }

        const size_type _Newcapacity = _Calculate_growth(_Newsize);

        if (_Myfirst) { // destroy and deallocate old array
            _Destroy(_Myfirst, _Mylast);
            _Getal().deallocate(_Myfirst, static_cast<size_type>(_Myend - _Myfirst));

            _Myfirst = nullptr;
            _Mylast  = nullptr;
            _Myend   = nullptr;
        }

        _Buy_raw(_Newcapacity);
    }

public:
    _CONSTEXPR20_CONTAINER void reserve(_CRT_GUARDOVERFLOW const size_type _Newcapacity) {
        // increase capacity to _Newcapacity (without geometric growth), provide strong guarantee
        if (_Newcapacity > capacity()) { // something to do (reserve() never shrinks)
            if (_Newcapacity > max_size()) {
                _Xlength();
            }

            _Reallocate_exactly(_Newcapacity);
        }
    }

    _CONSTEXPR20_CONTAINER void shrink_to_fit() { // reduce capacity to size, provide strong guarantee
        auto& _My_data         = _Mypair._Myval2;
        const pointer _Oldlast = _My_data._Mylast;
        if (_Oldlast != _My_data._Myend) { // something to do
            const pointer _Oldfirst = _My_data._Myfirst;
            if (_Oldfirst == _Oldlast) {
                _Tidy();
            } else {
                _Reallocate_exactly(static_cast<size_type>(_Oldlast - _Oldfirst));
            }
        }
    }

    _CONSTEXPR20_CONTAINER void pop_back() noexcept /* strengthened */ {
        auto& _My_data   = _Mypair._Myval2;
        pointer& _Mylast = _My_data._Mylast;

#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(_My_data._Myfirst != _Mylast, "vector empty before pop");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        _Orphan_range(_Mylast - 1, _Mylast);
        _Alty_traits::destroy(_Getal(), _Unfancy(_Mylast - 1));
        --_Mylast;
    }

    _CONSTEXPR20_CONTAINER iterator erase(const_iterator _Where) noexcept(
        is_nothrow_move_assignable_v<value_type>) /* strengthened */ {
        const pointer _Whereptr = _Where._Ptr;
        auto& _My_data          = _Mypair._Myval2;
        pointer& _Mylast        = _My_data._Mylast;

#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(
            _Where._Getcont() == _STD addressof(_My_data) && _Whereptr >= _My_data._Myfirst && _Mylast > _Whereptr,
            "vector erase iterator outside range");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        _Orphan_range(_Whereptr, _Mylast);
        _Move_unchecked(_Whereptr + 1, _Mylast, _Whereptr);
        _Alty_traits::destroy(_Getal(), _Unfancy(_Mylast - 1));
        --_Mylast;
        return iterator(_Whereptr, _STD addressof(_My_data));
    }

    _CONSTEXPR20_CONTAINER iterator erase(const_iterator _First, const_iterator _Last) noexcept(
        is_nothrow_move_assignable_v<value_type>) /* strengthened */ {
        const pointer _Firstptr = _First._Ptr;
        const pointer _Lastptr  = _Last._Ptr;
        auto& _My_data          = _Mypair._Myval2;
        pointer& _Mylast        = _My_data._Mylast;

#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(_First._Getcont() == _STD addressof(_My_data) && _Last._Getcont() == _STD addressof(_My_data)
                        && _Firstptr >= _My_data._Myfirst && _Lastptr >= _Firstptr && _Mylast >= _Lastptr,
            "vector erase iterator outside range");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        if (_Firstptr != _Lastptr) { // something to do, invalidate iterators
            _Orphan_range(_Firstptr, _Mylast);

            const pointer _Newlast = _Move_unchecked(_Lastptr, _Mylast, _Firstptr);
            _Destroy(_Newlast, _Mylast);
            _Mylast = _Newlast;
        }

        return iterator(_Firstptr, _STD addressof(_My_data));
    }

    _CONSTEXPR20_CONTAINER void clear() noexcept { // erase all
        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;

        _My_data._Orphan_all();
        _Destroy(_Myfirst, _Mylast);
        _Mylast = _Myfirst;
    }

    _CONSTEXPR20_CONTAINER void swap(vector& _Right) noexcept /* strengthened */ {
        if (this != _STD addressof(_Right)) {
            _Pocs(_Getal(), _Right._Getal());
            _Mypair._Myval2._Swap_val(_Right._Mypair._Myval2);
        }
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Ty* data() noexcept {
        return _Unfancy_maybe_null(_Mypair._Myval2._Myfirst);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const _Ty* data() const noexcept {
        return _Unfancy_maybe_null(_Mypair._Myval2._Myfirst);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER iterator begin() noexcept {
        auto& _My_data = _Mypair._Myval2;
        return iterator(_My_data._Myfirst, _STD addressof(_My_data));
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_iterator begin() const noexcept {
        auto& _My_data = _Mypair._Myval2;
        return const_iterator(_My_data._Myfirst, _STD addressof(_My_data));
    }

    _NODISCARD _CONSTEXPR20_CONTAINER iterator end() noexcept {
        auto& _My_data = _Mypair._Myval2;
        return iterator(_My_data._Mylast, _STD addressof(_My_data));
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_iterator end() const noexcept {
        auto& _My_data = _Mypair._Myval2;
        return const_iterator(_My_data._Mylast, _STD addressof(_My_data));
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reverse_iterator rbegin() noexcept {
        return reverse_iterator(end());
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator(end());
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reverse_iterator rend() noexcept {
        return reverse_iterator(begin());
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator(begin());
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_iterator cbegin() const noexcept {
        return begin();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_iterator cend() const noexcept {
        return end();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reverse_iterator crbegin() const noexcept {
        return rbegin();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reverse_iterator crend() const noexcept {
        return rend();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER pointer _Unchecked_begin() noexcept {
        return _Mypair._Myval2._Myfirst;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_pointer _Unchecked_begin() const noexcept {
        return _Mypair._Myval2._Myfirst;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER pointer _Unchecked_end() noexcept {
        return _Mypair._Myval2._Mylast;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_pointer _Unchecked_end() const noexcept {
        return _Mypair._Myval2._Mylast;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER bool empty() const noexcept {
        auto& _My_data = _Mypair._Myval2;
        return _My_data._Myfirst == _My_data._Mylast;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER size_type size() const noexcept {
        auto& _My_data = _Mypair._Myval2;
        return static_cast<size_type>(_My_data._Mylast - _My_data._Myfirst);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER size_type max_size() const noexcept {
        return (_STD min)(
            static_cast<size_type>((numeric_limits<difference_type>::max)()), _Alty_traits::max_size(_Getal()));
    }

    _NODISCARD _CONSTEXPR20_CONTAINER size_type capacity() const noexcept {
        auto& _My_data = _Mypair._Myval2;
        return static_cast<size_type>(_My_data._Myend - _My_data._Myfirst);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Ty& operator[](const size_type _Pos) noexcept /* strengthened */ {
        auto& _My_data = _Mypair._Myval2;
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(
            _Pos < static_cast<size_type>(_My_data._Mylast - _My_data._Myfirst), "vector subscript out of range");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        return _My_data._Myfirst[_Pos];
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const _Ty& operator[](const size_type _Pos) const noexcept /* strengthened */ {
        auto& _My_data = _Mypair._Myval2;
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(
            _Pos < static_cast<size_type>(_My_data._Mylast - _My_data._Myfirst), "vector subscript out of range");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        return _My_data._Myfirst[_Pos];
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Ty& at(const size_type _Pos) {
        auto& _My_data = _Mypair._Myval2;
        if (static_cast<size_type>(_My_data._Mylast - _My_data._Myfirst) <= _Pos) {
            _Xrange();
        }

        return _My_data._Myfirst[_Pos];
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const _Ty& at(const size_type _Pos) const {
        auto& _My_data = _Mypair._Myval2;
        if (static_cast<size_type>(_My_data._Mylast - _My_data._Myfirst) <= _Pos) {
            _Xrange();
        }

        return _My_data._Myfirst[_Pos];
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Ty& front() noexcept /* strengthened */ {
        auto& _My_data = _Mypair._Myval2;
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(_My_data._Myfirst != _My_data._Mylast, "front() called on empty vector");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        return *_My_data._Myfirst;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const _Ty& front() const noexcept /* strengthened */ {
        auto& _My_data = _Mypair._Myval2;
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(_My_data._Myfirst != _My_data._Mylast, "front() called on empty vector");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        return *_My_data._Myfirst;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Ty& back() noexcept /* strengthened */ {
        auto& _My_data = _Mypair._Myval2;
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(_My_data._Myfirst != _My_data._Mylast, "back() called on empty vector");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        return _My_data._Mylast[-1];
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const _Ty& back() const noexcept /* strengthened */ {
        auto& _My_data = _Mypair._Myval2;
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(_My_data._Myfirst != _My_data._Mylast, "back() called on empty vector");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        return _My_data._Mylast[-1];
    }

    _NODISCARD _CONSTEXPR20_CONTAINER allocator_type get_allocator() const noexcept {
        return static_cast<allocator_type>(_Getal());
    }

private:
    _CONSTEXPR20_CONTAINER pointer _Ufill(pointer _Dest, const size_type _Count, const _Ty& _Val) {
        // fill raw _Dest with _Count copies of _Val, using allocator
        return _Uninitialized_fill_n(_Dest, _Count, _Val, _Getal());
    }

    _CONSTEXPR20_CONTAINER pointer _Ufill(pointer _Dest, const size_type _Count, _Value_init_tag) {
        // fill raw _Dest with _Count value-initialized objects, using allocator
        return _Uninitialized_value_construct_n(_Dest, _Count, _Getal());
    }

    template <class _Iter>
    _CONSTEXPR20_CONTAINER pointer _Ucopy(_Iter _First, _Iter _Last, pointer _Dest) {
        // copy [_First, _Last) to raw _Dest, using allocator
        return _Uninitialized_copy(_First, _Last, _Dest, _Getal());
    }

    _CONSTEXPR20_CONTAINER pointer _Umove(pointer _First, pointer _Last, pointer _Dest) {
        // move [_First, _Last) to raw _Dest, using allocator
        return _Uninitialized_move(_First, _Last, _Dest, _Getal());
    }

    _CONSTEXPR20_CONTAINER void _Umove_if_noexcept1(pointer _First, pointer _Last, pointer _Dest, true_type) {
        // move [_First, _Last) to raw _Dest, using allocator
        _Uninitialized_move(_First, _Last, _Dest, _Getal());
    }

    _CONSTEXPR20_CONTAINER void _Umove_if_noexcept1(pointer _First, pointer _Last, pointer _Dest, false_type) {
        // copy [_First, _Last) to raw _Dest, using allocator
        _Uninitialized_copy(_First, _Last, _Dest, _Getal());
    }

    _CONSTEXPR20_CONTAINER void _Umove_if_noexcept(pointer _First, pointer _Last, pointer _Dest) {
        // move_if_noexcept [_First, _Last) to raw _Dest, using allocator
        _Umove_if_noexcept1(_First, _Last, _Dest,
            bool_constant<disjunction_v<is_nothrow_move_constructible<_Ty>, negation<is_copy_constructible<_Ty>>>>{});
    }

    _CONSTEXPR20_CONTAINER void _Destroy(pointer _First, pointer _Last) {
        // destroy [_First, _Last) using allocator
        _Destroy_range(_First, _Last, _Getal());
    }

    _CONSTEXPR20_CONTAINER size_type _Calculate_growth(const size_type _Newsize) const {
        // given _Oldcapacity and _Newsize, calculate geometric growth
        const size_type _Oldcapacity = capacity();
        const auto _Max              = max_size();

        if (_Oldcapacity > _Max - _Oldcapacity / 2) {
            return _Max; // geometric growth would overflow
        }

        const size_type _Geometric = _Oldcapacity + _Oldcapacity / 2;

        if (_Geometric < _Newsize) {
            return _Newsize; // geometric growth would be insufficient
        }

        return _Geometric; // geometric growth is sufficient
    }

    _CONSTEXPR20_CONTAINER void _Buy_raw(const size_type _Newcapacity) {
        // allocate array with _Newcapacity elements
        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;
        pointer& _Myend   = _My_data._Myend;

        _STL_INTERNAL_CHECK(!_Myfirst && !_Mylast && !_Myend); // check that *this is tidy
        _STL_INTERNAL_CHECK(0 < _Newcapacity && _Newcapacity <= max_size());

        const auto _Newvec = _Getal().allocate(_Newcapacity);
        _Myfirst           = _Newvec;
        _Mylast            = _Newvec;
        _Myend             = _Newvec + _Newcapacity;
    }

    _CONSTEXPR20_CONTAINER void _Buy_nonzero(const size_type _Newcapacity) {
        // allocate array with _Newcapacity elements
#ifdef _ENABLE_STL_INTERNAL_CHECK
        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;
        pointer& _Myend   = _My_data._Myend;
        _STL_INTERNAL_CHECK(!_Myfirst && !_Mylast && !_Myend); // check that *this is tidy
        _STL_INTERNAL_CHECK(0 < _Newcapacity);
#endif // _ENABLE_STL_INTERNAL_CHECK

        if (_Newcapacity > max_size()) {
            _Xlength();
        }

        _Buy_raw(_Newcapacity);
    }

    _CONSTEXPR20_CONTAINER void _Change_array(
        const pointer _Newvec, const size_type _Newsize, const size_type _Newcapacity) {
        // orphan all iterators, discard old array, acquire new array
        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;
        pointer& _Myend   = _My_data._Myend;

        _My_data._Orphan_all();

        if (_Myfirst) { // destroy and deallocate old array
            _Destroy(_Myfirst, _Mylast);
            _Getal().deallocate(_Myfirst, static_cast<size_type>(_Myend - _Myfirst));
        }

        _Myfirst = _Newvec;
        _Mylast  = _Newvec + _Newsize;
        _Myend   = _Newvec + _Newcapacity;
    }

    _CONSTEXPR20_CONTAINER void _Tidy() noexcept { // free all storage
        auto& _My_data    = _Mypair._Myval2;
        pointer& _Myfirst = _My_data._Myfirst;
        pointer& _Mylast  = _My_data._Mylast;
        pointer& _Myend   = _My_data._Myend;

        _My_data._Orphan_all();

        if (_Myfirst) { // destroy and deallocate old array
            _Destroy(_Myfirst, _Mylast);
            _Getal().deallocate(_Myfirst, static_cast<size_type>(_Myend - _Myfirst));

            _Myfirst = nullptr;
            _Mylast  = nullptr;
            _Myend   = nullptr;
        }
    }

    [[noreturn]] static void _Xlength() {
        _Xlength_error("vector too long");
    }

    [[noreturn]] static void _Xrange() {
        _Xout_of_range("invalid vector subscript");
    }

#if _ITERATOR_DEBUG_LEVEL == 2
    _CONSTEXPR20_CONTAINER void _Orphan_range_unlocked(pointer _First, pointer _Last) const {
        _Iterator_base12** _Pnext = &_Mypair._Myval2._Myproxy->_Myfirstiter;
        while (*_Pnext) {
            const auto _Pnextptr = static_cast<const_iterator&>(**_Pnext)._Ptr;
            if (_Pnextptr < _First || _Last < _Pnextptr) { // skip the iterator
                const auto _Temp = *_Pnext; // TRANSITION, VSO-1269037
                _Pnext           = &_Temp->_Mynextiter;
            } else { // orphan the iterator
                const auto _Temp = *_Pnext; // TRANSITION, VSO-1269037
                _Temp->_Myproxy  = nullptr;
                *_Pnext          = _Temp->_Mynextiter;
            }
        }
    }

    void _Orphan_range_locked(pointer _First, pointer _Last) const {
        _Lockit _Lock(_LOCK_DEBUG);
        _Orphan_range_unlocked(_First, _Last);
    }

    _CONSTEXPR20_CONTAINER void _Orphan_range(pointer _First, pointer _Last) const {
        // orphan iterators within specified (inclusive) range
#ifdef __cpp_lib_constexpr_dynamic_alloc
        if (_STD is_constant_evaluated()) {
            _Orphan_range_unlocked(_First, _Last);
        } else
#endif // __cpp_lib_constexpr_dynamic_alloc
        {
            _Orphan_range_locked(_First, _Last);
        }
    }
#else // ^^^ _ITERATOR_DEBUG_LEVEL == 2 ^^^ // vvv _ITERATOR_DEBUG_LEVEL != 2 vvv
    _CONSTEXPR20_CONTAINER void _Orphan_range(pointer, pointer) const {}
#endif // _ITERATOR_DEBUG_LEVEL != 2

    _NODISCARD _CONSTEXPR20_CONTAINER _Alty& _Getal() noexcept {
        return _Mypair._Get_first();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const _Alty& _Getal() const noexcept {
        return _Mypair._Get_first();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER iterator _Make_iterator(const pointer _Ptr) noexcept {
        return iterator(_Ptr, _STD addressof(_Mypair._Myval2));
    }

    _NODISCARD _CONSTEXPR20_CONTAINER iterator _Make_iterator_offset(const size_type _Offset) noexcept {
        // return the iterator begin() + _Offset without a debugging check
        auto& _My_data = _Mypair._Myval2;
        return iterator(_My_data._Myfirst + _Offset, _STD addressof(_My_data));
    }

    _Compressed_pair<_Alty, _Scary_val> _Mypair;
};

#if _HAS_CXX17
template <class _Iter, class _Alloc = allocator<_Iter_value_t<_Iter>>,
    enable_if_t<conjunction_v<_Is_iterator<_Iter>, _Is_allocator<_Alloc>>, int> = 0>
vector(_Iter, _Iter, _Alloc = _Alloc()) -> vector<_Iter_value_t<_Iter>, _Alloc>;
#endif // _HAS_CXX17

template <class _Alloc>
class vector<bool, _Alloc>;

using _Vbase         = unsigned int; // word type for vector<bool> representation
constexpr int _VBITS = 8 * sizeof(_Vbase); // at least CHAR_BITS bits per word

template <class _Ty, class _Alloc>
_NODISCARD _CONSTEXPR20_CONTAINER bool operator==(const vector<_Ty, _Alloc>& _Left, const vector<_Ty, _Alloc>& _Right) {
    if (_Left.size() != _Right.size()) {
        return false;
    }

    if constexpr (is_same_v<_Ty, bool>) {
        return _STD equal(
            _Left._Myvec._Unchecked_begin(), _Left._Myvec._Unchecked_end(), _Right._Myvec._Unchecked_begin());
    } else {
        return _STD equal(_Left._Unchecked_begin(), _Left._Unchecked_end(), _Right._Unchecked_begin());
    }
}

#if !_HAS_CXX20
template <class _Ty, class _Alloc>
_NODISCARD bool operator!=(const vector<_Ty, _Alloc>& _Left, const vector<_Ty, _Alloc>& _Right) {
    return !(_Left == _Right);
}
#endif // !_HAS_CXX20

// Optimize vector<bool> lexicographical comparisons.

// There are several endianness/ordering issues to consider here.
// * Machine endianness is irrelevant. (That affects how an unsigned int is stored
//   as a sequence of bytes. While all of our supported architectures are little-endian,
//   that's irrelevant as long as we avoid reinterpreting unsigned int as a sequence of bytes.)
// * Appending bits to vector<bool> eventually appends words to its underlying storage.
//   For example, vb[10] is stored within vb._Myvec[0], while vb[100] is stored within vb._Myvec[3].
//   This allows us to translate lexicographical comparisons from theoretical bits to physical words.
// * Unsigned integers are written and compared as big-endian (most significant bit first).
//   For example, 0x10u > 0x07u.
// * However, vector<bool> packs bits into words as little-endian (least significant bit first).
//   For example, vector<bool>{false, true, true, true} stores 0b0000'0000'0000'0000'0000'0000'0000'1110u.
// We could bit-reverse words before comparing, but we just need to find the least significant bit that differs.

template <class _Ret>
struct _Vbase_compare_three_way {
    _NODISCARD constexpr _Ret operator()(const _Vbase _Left, const _Vbase _Right) const noexcept {
        const _Vbase _Differing_bits = _Left ^ _Right;

        if (_Differing_bits == 0) { // improves _Countr_zero codegen below
#ifdef __cpp_lib_concepts
            return strong_ordering::equal;
#else // ^^^ defined(__cpp_lib_concepts) / !defined(__cpp_lib_concepts) vvv
            return 0;
#endif // ^^^ !defined(__cpp_lib_concepts) ^^^
        }

        const int _Bit_index = _Countr_zero(_Differing_bits); // number of least significant bits that match
        _STL_INTERNAL_CHECK(_Bit_index < _VBITS); // because we return early for equality

        const _Vbase _Mask = _Vbase{1} << _Bit_index; // selects the least significant bit that differs

        // Instead of comparing (_Left & _Mask) to (_Right & _Mask), we know that exactly one side will be zero.
#ifdef __cpp_lib_concepts
        return (_Left & _Mask) == 0 ? strong_ordering::less : strong_ordering::greater;
#else // ^^^ defined(__cpp_lib_concepts) / !defined(__cpp_lib_concepts) vvv
        return (_Left & _Mask) == 0 ? -1 : 1;
#endif // ^^^ !defined(__cpp_lib_concepts) ^^^
    }
};

#ifdef __cpp_lib_concepts
template <class _Ty, class _Alloc>
_NODISCARD _CONSTEXPR20_CONTAINER _Synth_three_way_result<_Ty> operator<=>(
    const vector<_Ty, _Alloc>& _Left, const vector<_Ty, _Alloc>& _Right) {
    if constexpr (is_same_v<_Ty, bool>) {
        // This optimization works because vector<bool> "trims" its underlying storage by zeroing out unused bits.
        const auto _Min_word_size = (_STD min)(_Left._Myvec.size(), _Right._Myvec.size());
        const auto _Left_words    = _Left._Myvec._Unchecked_begin();
        const auto _Right_words   = _Right._Myvec._Unchecked_begin();

        using _Comp = _Vbase_compare_three_way<strong_ordering>;

        const strong_ordering _Word_comparison = _STD lexicographical_compare_three_way(
            _Left_words, _Left_words + _Min_word_size, _Right_words, _Right_words + _Min_word_size, _Comp{});

        if (_Word_comparison != 0) {
            return _Word_comparison;
        }

        return _Left.size() <=> _Right.size();
    } else {
        return _STD lexicographical_compare_three_way(_Left._Unchecked_begin(), _Left._Unchecked_end(),
            _Right._Unchecked_begin(), _Right._Unchecked_end(), _Synth_three_way{});
    }
}
#else // ^^^ defined(__cpp_lib_concepts) / !defined(__cpp_lib_concepts) vvv
template <class _Ty, class _Alloc>
_NODISCARD _CONSTEXPR20_CONTAINER bool operator<(const vector<_Ty, _Alloc>& _Left, const vector<_Ty, _Alloc>& _Right) {
    if constexpr (is_same_v<_Ty, bool>) {
        // This optimization works because vector<bool> "trims" its underlying storage by zeroing out unused bits.
        auto _First = _Left._Myvec._Unchecked_begin();
        auto _Other = _Right._Myvec._Unchecked_begin();

        const auto _Last = _First + (_STD min)(_Left._Myvec.size(), _Right._Myvec.size());

        for (; _First != _Last; ++_First, (void) ++_Other) {
            using _Comp = _Vbase_compare_three_way<signed char>;
            const auto _Result = _Comp{}(*_First, *_Other);

            if (_Result < 0) {
                return true;
            } else if (_Result > 0) {
                return false;
            }
        }

        return _Left.size() < _Right.size();
    } else {
        return _STD lexicographical_compare(
            _Left._Unchecked_begin(), _Left._Unchecked_end(), _Right._Unchecked_begin(), _Right._Unchecked_end());
    }
}

template <class _Ty, class _Alloc>
_NODISCARD _CONSTEXPR20_CONTAINER bool operator>(const vector<_Ty, _Alloc>& _Left, const vector<_Ty, _Alloc>& _Right) {
    return _Right < _Left;
}

template <class _Ty, class _Alloc>
_NODISCARD _CONSTEXPR20_CONTAINER bool operator<=(const vector<_Ty, _Alloc>& _Left, const vector<_Ty, _Alloc>& _Right) {
    return !(_Right < _Left);
}

template <class _Ty, class _Alloc>
_NODISCARD _CONSTEXPR20_CONTAINER bool operator>=(const vector<_Ty, _Alloc>& _Left, const vector<_Ty, _Alloc>& _Right) {
    return !(_Left < _Right);
}
#endif // ^^^ !defined(__cpp_lib_concepts) ^^^

template <class _Ty, class _Alloc>
_CONSTEXPR20_CONTAINER void swap(vector<_Ty, _Alloc>& _Left, vector<_Ty, _Alloc>& _Right) noexcept /* strengthened */ {
    _Left.swap(_Right);
}

#if _HAS_CXX20
template <class _Ty, class _Alloc, class _Uty>
_CONSTEXPR20_CONTAINER typename vector<_Ty, _Alloc>::size_type erase(vector<_Ty, _Alloc>& _Cont, const _Uty& _Val) {
    return _Erase_remove(_Cont, _Val);
}

template <class _Ty, class _Alloc, class _Pr>
_CONSTEXPR20_CONTAINER typename vector<_Ty, _Alloc>::size_type erase_if(vector<_Ty, _Alloc>& _Cont, _Pr _Pred) {
    return _Erase_remove_if(_Cont, _Pass_fn(_Pred));
}
#endif // _HAS_CXX20

// CLASS TEMPLATE vector<bool, Alloc> AND FRIENDS
template <class _Alloc0>
struct _Wrap_alloc { // TRANSITION, ABI compat, preserves symbol names of vector<bool>::iterator
    using _Alloc = _Alloc0;
};

// CLASS _Vb_iter_base
template <class _Alvbase_wrapped>
class _Vb_iter_base : public _Iterator_base {
    // store information common to reference and iterators
public:
    using _Alvbase         = typename _Alvbase_wrapped::_Alloc;
    using _Size_type       = typename allocator_traits<_Alvbase>::size_type;
    using _Difference_type = typename allocator_traits<_Alvbase>::difference_type;
    using _Mycont          = vector<bool, _Rebind_alloc_t<_Alvbase, bool>>;

    _CONSTEXPR20_CONTAINER _Vb_iter_base() = default;

    _CONSTEXPR20_CONTAINER _Vb_iter_base(const _Vbase* _Ptr, _Size_type _Off, const _Container_base* _Mypvbool) noexcept
        : _Myptr(_Ptr), _Myoff(_Off) {
        this->_Adopt(_Mypvbool);
    }

    // TRANSITION, DevCom-1331017
    _CONSTEXPR20_CONTAINER _Vb_iter_base& operator=(const _Vb_iter_base&) noexcept = default;

    _CONSTEXPR20_CONTAINER void _Advance(_Size_type _Off) noexcept {
        _Myoff += _Off;
        _Myptr += _Myoff / _VBITS;
        _Myoff %= _VBITS;
    }

#if _ITERATOR_DEBUG_LEVEL != 0
    _CONSTEXPR20_CONTAINER _Difference_type _Total_off(const _Mycont* _Cont) const noexcept {
        return static_cast<_Difference_type>(_VBITS * (_Myptr - _Cont->_Myvec.data()) + _Myoff);
    }
#endif // _ITERATOR_DEBUG_LEVEL != 0

    const _Vbase* _Myptr = nullptr;
    _Size_type _Myoff    = 0;
};

// CLASS _Vb_reference
template <class _Alvbase_wrapped>
class _Vb_reference : public _Vb_iter_base<_Alvbase_wrapped> {
    // reference to a bit within a base word
    using _Mybase          = _Vb_iter_base<_Alvbase_wrapped>;
    using _Mycont          = typename _Mybase::_Mycont;
    using _Difference_type = typename _Mybase::_Difference_type;

    // TRANSITION, ABI: non-trivial constructor
    _CONSTEXPR20_CONTAINER _Vb_reference() = default;

public:
    _CONSTEXPR20_CONTAINER _Vb_reference(const _Vb_reference&) = default;

    _CONSTEXPR20_CONTAINER _Vb_reference(const _Mybase& _Right) noexcept
        : _Mybase(_Right._Myptr, _Right._Myoff, _Right._Getcont()) {}

    _CONSTEXPR20_CONTAINER _Vb_reference& operator=(const _Vb_reference& _Right) noexcept {
        return *this = static_cast<bool>(_Right);
    }

    _CONSTEXPR20_CONTAINER _Vb_reference& operator=(bool _Val) noexcept {
        if (_Val) {
            *const_cast<_Vbase*>(_Getptr()) |= _Mask();
        } else {
            *const_cast<_Vbase*>(_Getptr()) &= ~_Mask();
        }

        return *this;
    }

    _CONSTEXPR20_CONTAINER void flip() noexcept {
        *const_cast<_Vbase*>(_Getptr()) ^= _Mask();
    }

    _CONSTEXPR20_CONTAINER operator bool() const noexcept {
        return (*_Getptr() & _Mask()) != 0;
    }

    _CONSTEXPR20_CONTAINER const _Vbase* _Getptr() const noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Cont = static_cast<const _Mycont*>(this->_Getcont());
        _STL_VERIFY(_Cont, "cannot dereference value-initialized vector<bool> iterator");
        _STL_VERIFY(this->_Total_off(_Cont) <= static_cast<_Difference_type>(_Cont->_Mysize),
            "vector<bool> iterator not dereferenceable");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return this->_Myptr;
    }

    friend _CONSTEXPR20_CONTAINER void swap(_Vb_reference _Left, _Vb_reference _Right) noexcept {
        bool _Val = _Left; // NOT _STD swap
        _Left     = _Right;
        _Right    = _Val;
    }

protected:
    _CONSTEXPR20_CONTAINER _Vbase _Mask() const noexcept {
        return static_cast<_Vbase>(1) << this->_Myoff;
    }
};

// CLASS _Vb_const_iterator
template <class _Alvbase_wrapped>
class _Vb_const_iterator : public _Vb_iter_base<_Alvbase_wrapped> {
private:
    using _Mybase = _Vb_iter_base<_Alvbase_wrapped>;

public:
    using _Mycont          = typename _Mybase::_Mycont;
    using _Difference_type = typename _Mybase::_Difference_type;
    using _Size_type       = typename _Mybase::_Size_type;
    using _Reft            = _Vb_reference<_Alvbase_wrapped>;
    using const_reference  = bool;

    using iterator_category = random_access_iterator_tag;
    using value_type        = bool;
    using difference_type   = typename _Mybase::_Difference_type;
    using pointer           = const_reference*;
    using reference         = const_reference;

    _CONSTEXPR20_CONTAINER _Vb_const_iterator() = default;

    _CONSTEXPR20_CONTAINER _Vb_const_iterator(const _Vbase* _Ptr, const _Container_base* _Mypvbool) noexcept
        : _Mybase(_Ptr, 0, _Mypvbool) {}

    // TRANSITION, DevCom-1331017
    _CONSTEXPR20_CONTAINER _Vb_const_iterator& operator=(const _Vb_const_iterator&) noexcept = default;

    _NODISCARD _CONSTEXPR20_CONTAINER const_reference operator*() const noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Cont = static_cast<const _Mycont*>(this->_Getcont());
        _STL_VERIFY(_Cont, "cannot dereference value-initialized vector<bool> iterator");
        _STL_VERIFY(this->_Total_off(_Cont) < static_cast<_Difference_type>(_Cont->_Mysize),
            "vector<bool> iterator not dereferenceable");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return _Reft(*this);
    }

    _CONSTEXPR20_CONTAINER _Vb_const_iterator& operator++() noexcept {
        _Inc();
        return *this;
    }

    _CONSTEXPR20_CONTAINER _Vb_const_iterator operator++(int) noexcept {
        _Vb_const_iterator _Tmp = *this;
        _Inc();
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vb_const_iterator& operator--() noexcept {
        _Dec();
        return *this;
    }

    _CONSTEXPR20_CONTAINER _Vb_const_iterator operator--(int) noexcept {
        _Vb_const_iterator _Tmp = *this;
        _Dec();
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vb_const_iterator& operator+=(const difference_type _Off) noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        if (_Off != 0) {
            const auto _Cont = static_cast<const _Mycont*>(this->_Getcont());
            _STL_VERIFY(_Cont, "cannot seek value-initialized vector<bool> iterator");
            const auto _Start_offset = this->_Total_off(_Cont);
            if (_Off < 0) {
                _STL_VERIFY(-_Start_offset <= _Off, "cannot seek vector<bool> iterator before begin");
            } else if (0 < _Off) {
                _STL_VERIFY(_Off <= static_cast<_Difference_type>(_Cont->_Mysize - _Start_offset),
                    "cannot seek vector<bool> iterator after end");
            }
        }
#endif // _ITERATOR_DEBUG_LEVEL != 0

        if (_Off < 0 && this->_Myoff < 0 - static_cast<_Size_type>(_Off)) { // add negative increment
            this->_Myoff += static_cast<_Size_type>(_Off);
            this->_Myptr -= 1 + (static_cast<_Size_type>(-1) - this->_Myoff) / _VBITS;
            this->_Myoff %= _VBITS;
        } else { // add non-negative increment
            this->_Myoff += static_cast<_Size_type>(_Off);
            this->_Myptr += this->_Myoff / _VBITS;
            this->_Myoff %= _VBITS;
        }
        return *this;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Vb_const_iterator operator+(const difference_type _Off) const noexcept {
        _Vb_const_iterator _Tmp = *this;
        _Tmp += _Off; // TRANSITION, LLVM-49342
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vb_const_iterator& operator-=(const difference_type _Off) noexcept {
        return *this += -_Off;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Vb_const_iterator operator-(const difference_type _Off) const noexcept {
        _Vb_const_iterator _Tmp = *this;
        _Tmp -= _Off; // TRANSITION, LLVM-49342
        return _Tmp;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER difference_type operator-(const _Vb_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return static_cast<difference_type>(_VBITS * (this->_Myptr - _Right._Myptr))
             + static_cast<difference_type>(this->_Myoff) - static_cast<difference_type>(_Right._Myoff);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reference operator[](const difference_type _Off) const noexcept {
        return *(*this + _Off);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER bool operator==(const _Vb_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return this->_Myptr == _Right._Myptr && this->_Myoff == _Right._Myoff;
    }

#if _HAS_CXX20
    _NODISCARD _CONSTEXPR20_CONTAINER strong_ordering operator<=>(const _Vb_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        if (const auto _CmpResult = this->_Myptr <=> _Right._Myptr; _CmpResult != 0) {
            return _CmpResult;
        }
        return this->_Myoff <=> _Right._Myoff;
    }
#else // ^^^ _HAS_CXX20 ^^^ / vvv !_HAS_CXX20 vvv
    _NODISCARD bool operator!=(const _Vb_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }

    _NODISCARD bool operator<(const _Vb_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return this->_Myptr < _Right._Myptr || (this->_Myptr == _Right._Myptr && this->_Myoff < _Right._Myoff);
    }

    _NODISCARD bool operator>(const _Vb_const_iterator& _Right) const noexcept {
        return _Right < *this;
    }

    _NODISCARD bool operator<=(const _Vb_const_iterator& _Right) const noexcept {
        return !(_Right < *this);
    }

    _NODISCARD bool operator>=(const _Vb_const_iterator& _Right) const noexcept {
        return !(*this < _Right);
    }
#endif // !_HAS_CXX20

    _CONSTEXPR20_CONTAINER void _Compat(const _Vb_const_iterator& _Right) const noexcept {
        // test for compatible iterator pair
#if _ITERATOR_DEBUG_LEVEL == 0
        (void) _Right;
#else // _ITERATOR_DEBUG_LEVEL == 0
        _STL_VERIFY(this->_Getcont() == _Right._Getcont(), "vector<bool> iterators incompatible");
#endif // _ITERATOR_DEBUG_LEVEL
    }

#if _ITERATOR_DEBUG_LEVEL != 0
    using _Prevent_inheriting_unwrap = _Vb_const_iterator;

    friend _CONSTEXPR20_CONTAINER void _Verify_range(
        const _Vb_const_iterator& _First, const _Vb_const_iterator& _Last) noexcept {
        // note _Compat check inside <=
        _STL_VERIFY(_First <= _Last, "vector<bool> iterator range transposed");
    }
#endif // _ITERATOR_DEBUG_LEVEL != 0

    _CONSTEXPR20_CONTAINER void _Dec() noexcept { // decrement bit position
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Cont = static_cast<const _Mycont*>(this->_Getcont());
        _STL_VERIFY(_Cont, "cannot decrement value-initialized vector<bool> iterator");
        _STL_VERIFY(this->_Total_off(_Cont) > 0, "cannot decrement vector<bool> begin iterator");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        if (this->_Myoff != 0) {
            --this->_Myoff;
        } else { // move to previous word
            this->_Myoff = _VBITS - 1;
            --this->_Myptr;
        }
    }

    _CONSTEXPR20_CONTAINER void _Inc() noexcept { // increment bit position
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Cont = static_cast<const _Mycont*>(this->_Getcont());
        _STL_VERIFY(_Cont, "cannot increment value-initialized vector<bool> iterator");
        _STL_VERIFY(this->_Total_off(_Cont) < static_cast<_Difference_type>(_Cont->_Mysize),
            "cannot increment vector<bool> end iterator");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        if (this->_Myoff < _VBITS - 1) {
            ++this->_Myoff;
        } else { // move to next word
            this->_Myoff = 0;
            ++this->_Myptr;
        }
    }
};

template <class _Alvbase_wrapped>
_NODISCARD _CONSTEXPR20_CONTAINER _Vb_const_iterator<_Alvbase_wrapped> operator+(
    typename _Vb_const_iterator<_Alvbase_wrapped>::difference_type _Off,
    _Vb_const_iterator<_Alvbase_wrapped> _Right) noexcept {
    return _Right += _Off;
}

// CLASS _Vb_iterator
template <class _Alvbase_wrapped>
class _Vb_iterator : public _Vb_const_iterator<_Alvbase_wrapped> {
public:
    using _Mybase          = _Vb_const_iterator<_Alvbase_wrapped>;
    using _Mycont          = typename _Mybase::_Mycont;
    using _Difference_type = typename _Mybase::_Difference_type;

    using _Reft           = _Vb_reference<_Alvbase_wrapped>;
    using const_reference = bool;

    using iterator_category = random_access_iterator_tag;
    using value_type        = bool;
    using difference_type   = typename _Mybase::difference_type;
    using pointer           = _Reft*;
    using reference         = _Reft;

    using _Mybase::_Mybase;

    _NODISCARD _CONSTEXPR20_CONTAINER reference operator*() const noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Cont = static_cast<const _Mycont*>(this->_Getcont());
        _STL_VERIFY(_Cont, "cannot dereference value-initialized vector<bool> iterator");
        _STL_VERIFY(this->_Total_off(_Cont) < static_cast<_Difference_type>(_Cont->_Mysize),
            "vector<bool> iterator not dereferenceable");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return _Reft(*this);
    }

    // TRANSITION, DevCom-1331017
    _CONSTEXPR20_CONTAINER _Vb_iterator& operator=(const _Vb_iterator&) noexcept = default;

    _CONSTEXPR20_CONTAINER _Vb_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _CONSTEXPR20_CONTAINER _Vb_iterator operator++(int) noexcept {
        _Vb_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vb_iterator& operator--() noexcept {
        _Mybase::operator--();
        return *this;
    }

    _CONSTEXPR20_CONTAINER _Vb_iterator operator--(int) noexcept {
        _Vb_iterator _Tmp = *this;
        _Mybase::operator--();
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vb_iterator& operator+=(const difference_type _Off) noexcept {
        _Mybase::operator+=(_Off);
        return *this;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER _Vb_iterator operator+(const difference_type _Off) const noexcept {
        _Vb_iterator _Tmp = *this;
        _Tmp += _Off; // TRANSITION, LLVM-49342
        return _Tmp;
    }

    _CONSTEXPR20_CONTAINER _Vb_iterator& operator-=(const difference_type _Off) noexcept {
        _Mybase::operator-=(_Off);
        return *this;
    }

    using _Mybase::operator-;

    _NODISCARD _CONSTEXPR20_CONTAINER _Vb_iterator operator-(const difference_type _Off) const noexcept {
        _Vb_iterator _Tmp = *this;
        _Tmp -= _Off; // TRANSITION, LLVM-49342
        return _Tmp;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reference operator[](const difference_type _Off) const noexcept {
        return *(*this + _Off);
    }

    using _Prevent_inheriting_unwrap = _Vb_iterator;
};

template <class _Alvbase_wrapped>
_NODISCARD _CONSTEXPR20_CONTAINER _Vb_iterator<_Alvbase_wrapped> operator+(
    typename _Vb_iterator<_Alvbase_wrapped>::difference_type _Off, _Vb_iterator<_Alvbase_wrapped> _Right) noexcept {
    return _Right += _Off;
}

// CLASS TEMPLATE _Vb_val
template <class _Alloc>
class _Vb_val : public _Container_base {
public:
    using _Alvbase         = _Rebind_alloc_t<_Alloc, _Vbase>;
    using _Alvbase_traits  = allocator_traits<_Alvbase>;
    using _Vectype         = vector<_Vbase, _Alvbase>;
    using _Alvbase_wrapped = _Wrap_alloc<_Alvbase>;
    using size_type        = typename _Alvbase_traits::size_type;

    _CONSTEXPR20_CONTAINER _Vb_val() noexcept(is_nothrow_default_constructible_v<_Vectype>) : _Myvec(), _Mysize(0) {
        this->_Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alvbase, _Getal()));
    }

    _CONSTEXPR20_CONTAINER _Vb_val(const _Alloc& _Al) noexcept(is_nothrow_constructible_v<_Vectype, _Alvbase>)
        : _Myvec(static_cast<_Alvbase>(_Al)), _Mysize(0) {
        this->_Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alvbase, _Getal()));
    }

    _CONSTEXPR20_CONTAINER _Vb_val(size_type _Count, const bool& _Val)
        : _Myvec(_Nw(_Count), static_cast<_Vbase>(_Val ? -1 : 0)), _Mysize(0) {
        this->_Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alvbase, _Getal()));
    }

    _CONSTEXPR20_CONTAINER _Vb_val(size_type _Count, const bool& _Val, const _Alloc& _Al)
        : _Myvec(_Nw(_Count), static_cast<_Vbase>(_Val ? -1 : 0), static_cast<_Alvbase>(_Al)), _Mysize(0) {
        this->_Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alvbase, _Getal()));
    }

    _CONSTEXPR20_CONTAINER _Vb_val(const _Vb_val& _Right) : _Myvec(_Right._Myvec), _Mysize(_Right._Mysize) {
        this->_Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alvbase, _Getal()));
    }

    _CONSTEXPR20_CONTAINER _Vb_val(const _Vb_val& _Right, const _Alloc& _Al)
        : _Myvec(_Right._Myvec, static_cast<_Alvbase>(_Al)), _Mysize(_Right._Mysize) {
        this->_Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alvbase, _Getal()));
    }

    _CONSTEXPR20_CONTAINER _Vb_val(_Vb_val&& _Right) noexcept(is_nothrow_move_constructible_v<_Vectype>)
        : _Myvec(_STD move(_Right._Myvec)), _Mysize(_STD exchange(_Right._Mysize, size_type{0})) {
        this->_Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alvbase, _Getal()));
    }

    _CONSTEXPR20_CONTAINER _Vb_val(_Vb_val&& _Right, const _Alloc& _Al) noexcept(
        is_nothrow_constructible_v<_Vectype, _Vectype, _Alvbase>)
        : _Myvec(_STD move(_Right._Myvec), static_cast<_Alvbase>(_Al)), _Mysize(_Right._Mysize) {
        if (_Right._Myvec.empty()) {
            // we took _Right's buffer, so zero out size
            _Right._Mysize = 0;
        }

        this->_Alloc_proxy(_GET_PROXY_ALLOCATOR(_Alvbase, _Getal()));
    }

    _CONSTEXPR20_CONTAINER ~_Vb_val() noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        this->_Orphan_all();
        auto&& _Alproxy = _GET_PROXY_ALLOCATOR(_Alvbase, this->_Getal());
        _Delete_plain_internal(_Alproxy, _STD exchange(this->_Myproxy, nullptr));
#endif // _ITERATOR_DEBUG_LEVEL != 0
    }

    _CONSTEXPR20_CONTAINER _Alvbase& _Getal() noexcept {
        return _Myvec._Getal();
    }

    _CONSTEXPR20_CONTAINER const _Alvbase& _Getal() const noexcept {
        return _Myvec._Getal();
    }

    static _CONSTEXPR20_CONTAINER size_type _Nw(size_type _Count) noexcept {
        return (_Count + _VBITS - 1) / _VBITS;
    }

    _Vectype _Myvec; // base vector of words
    size_type _Mysize; // current length of sequence
};

// CLASS vector<bool>
template <class _Alloc>
class vector<bool, _Alloc> : public _Vb_val<_Alloc> {
public:
    static_assert(!_ENFORCE_MATCHING_ALLOCATORS || is_same_v<bool, typename _Alloc::value_type>,
        _MISMATCHED_ALLOCATOR_MESSAGE("vector<bool, Allocator>", "bool"));

    using _Mybase          = _Vb_val<_Alloc>;
    using _Alvbase_wrapped = typename _Mybase::_Alvbase_wrapped;
    using _Alvbase         = typename _Mybase::_Alvbase;
    using _Alvbase_traits  = typename _Mybase::_Alvbase_traits;

    using size_type       = typename _Alvbase_traits::size_type;
    using difference_type = typename _Alvbase_traits::difference_type;
    using allocator_type  = _Alloc;

    using reference       = _Vb_reference<_Alvbase_wrapped>;
    using const_reference = bool;
    using value_type      = bool;

    using _Reft          = reference;
    using iterator       = _Vb_iterator<_Alvbase_wrapped>;
    using const_iterator = _Vb_const_iterator<_Alvbase_wrapped>;

    using pointer                = iterator;
    using const_pointer          = const_iterator;
    using reverse_iterator       = _STD reverse_iterator<iterator>;
    using const_reverse_iterator = _STD reverse_iterator<const_iterator>;

    static const int _VBITS = _STD _VBITS;
    enum { _EEN_VBITS = _VBITS }; // helper for expression evaluator

    _CONSTEXPR20_CONTAINER vector() noexcept(is_nothrow_default_constructible_v<_Mybase>) // strengthened
        : _Mybase() {}

    _CONSTEXPR20_CONTAINER explicit vector(const _Alloc& _Al) noexcept(
        is_nothrow_constructible_v<_Mybase, const _Alloc&>) // strengthened
        : _Mybase(_Al) {}

    _CONSTEXPR20_CONTAINER explicit vector(_CRT_GUARDOVERFLOW size_type _Count, const _Alloc& _Al = _Alloc())
        : _Mybase(_Count, false, _Al) {
        _Trim(_Count);
    }

    _CONSTEXPR20_CONTAINER vector(_CRT_GUARDOVERFLOW size_type _Count, const bool& _Val, const _Alloc& _Al = _Alloc())
        : _Mybase(_Count, _Val, _Al) {
        _Trim(_Count);
    }

    _CONSTEXPR20_CONTAINER vector(const vector& _Right) : _Mybase(_Right) {}

    _CONSTEXPR20_CONTAINER vector(const vector& _Right, const _Alloc& _Al) : _Mybase(_Right, _Al) {}

    template <class _Iter, enable_if_t<_Is_iterator_v<_Iter>, int> = 0>
    _CONSTEXPR20_CONTAINER vector(_Iter _First, _Iter _Last, const _Alloc& _Al = _Alloc()) : _Mybase(_Al) {
        _BConstruct(_First, _Last);
    }

    template <class _Iter>
    _CONSTEXPR20_CONTAINER void _BConstruct(_Iter _First, _Iter _Last) {
        insert(begin(), _First, _Last);
    }

    _CONSTEXPR20_CONTAINER vector(vector&& _Right) noexcept(is_nothrow_move_constructible_v<_Mybase>) // strengthened
        : _Mybase(_STD move(_Right)) {
        this->_Swap_proxy_and_iterators(_Right);
    }

    _CONSTEXPR20_CONTAINER vector(vector&& _Right, const _Alloc& _Al) noexcept(
        is_nothrow_constructible_v<_Mybase, _Mybase, const _Alloc&>)
        : _Mybase(_STD move(_Right), _Al) {
        if constexpr (!_Alvbase_traits::is_always_equal::value) {
            if (this->_Getal() != _Right._Getal()) {
                return;
            }
        }

        this->_Swap_proxy_and_iterators(_Right);
    }

private:
#if _ITERATOR_DEBUG_LEVEL != 0
    _CONSTEXPR20_CONTAINER void _Move_assign(vector& _Right, _Equal_allocators) noexcept {
        this->_Myvec  = _STD move(_Right._Myvec);
        this->_Mysize = _STD exchange(_Right._Mysize, size_type{0});
        this->_Swap_proxy_and_iterators(_Right);
    }

    _CONSTEXPR20_CONTAINER void _Move_assign(vector& _Right, _Propagate_allocators) noexcept {
        using _Alproxy_type = _Rebind_alloc_t<_Alvbase, _Container_proxy>;
        if (this->_Getal() != _Right._Getal()) { // reload proxy
            // intentionally slams into noexcept on OOM, TRANSITION, VSO-466800
            _Alproxy_type _Oldal(this->_Getal());
            _Alproxy_type _Right_proxy_al(_Right._Getal());
            _Container_proxy_ptr<_Alvbase> _Proxy(_Right_proxy_al, _Leave_proxy_unbound{});
            this->_Myvec  = _STD move(_Right._Myvec);
            this->_Mysize = _STD exchange(_Right._Mysize, size_type{0});
            _Proxy._Bind(_Oldal, this);
            this->_Swap_proxy_and_iterators(_Right);
            return;
        }

        this->_Myvec  = _STD move(_Right._Myvec);
        this->_Mysize = _STD exchange(_Right._Mysize, size_type{0});
        this->_Swap_proxy_and_iterators(_Right);
    }

    _CONSTEXPR20_CONTAINER void _Move_assign(vector& _Right, _No_propagate_allocators) {
        this->_Myvec  = _STD move(_Right._Myvec);
        this->_Mysize = _Right._Mysize;
        if (_Right._Myvec.empty()) {
            // we took _Right's buffer, so zero out size
            _Right._Mysize = 0;
        }

        if (this->_Getal() == _Right._Getal()) {
            this->_Swap_proxy_and_iterators(_Right);
        }
    }
#endif // _ITERATOR_DEBUG_LEVEL != 0

public:
    _CONSTEXPR20_CONTAINER vector& operator=(vector&& _Right) noexcept(is_nothrow_move_assignable_v<_Mybase>) {
        if (this != _STD addressof(_Right)) {
#if _ITERATOR_DEBUG_LEVEL == 0
            this->_Myvec  = _STD move(_Right._Myvec);
            this->_Mysize = _STD exchange(_Right._Mysize, size_type{0});
#else // ^^^ _ITERATOR_DEBUG_LEVEL == 0 ^^^ // vvv _ITERATOR_DEBUG_LEVEL != 0 vvv
            this->_Orphan_all();
            _Move_assign(_Right, _Choose_pocma<_Alvbase>{});
#endif // _ITERATOR_DEBUG_LEVEL == 0
        }
        return *this;
    }

    template <class... _Valty>
    _CONSTEXPR20_CONTAINER decltype(auto) emplace_back(_Valty&&... _Val) {
        bool _Tmp(_STD forward<_Valty>(_Val)...);
        push_back(_Tmp);

#if _HAS_CXX17
        return back();
#endif // _HAS_CXX17
    }

    template <class... _Valty>
    _CONSTEXPR20_CONTAINER iterator emplace(const_iterator _Where, _Valty&&... _Val) {
        bool _Tmp(_STD forward<_Valty>(_Val)...);
        return insert(_Where, _Tmp);
    }

    _CONSTEXPR20_CONTAINER vector(initializer_list<bool> _Ilist, const _Alloc& _Al = allocator_type())
        : _Mybase(0, false, _Al) {
        insert(begin(), _Ilist.begin(), _Ilist.end());
    }

    _CONSTEXPR20_CONTAINER vector& operator=(initializer_list<bool> _Ilist) {
        assign(_Ilist.begin(), _Ilist.end());
        return *this;
    }

    _CONSTEXPR20_CONTAINER void assign(initializer_list<bool> _Ilist) {
        assign(_Ilist.begin(), _Ilist.end());
    }

    _CONSTEXPR20_CONTAINER iterator insert(const_iterator _Where, initializer_list<bool> _Ilist) {
        return insert(_Where, _Ilist.begin(), _Ilist.end());
    }

    _CONSTEXPR20_CONTAINER ~vector() noexcept {}

private:
#if _ITERATOR_DEBUG_LEVEL != 0
    _CONSTEXPR20_CONTAINER void _Copy_assign(const vector& _Right, false_type) {
        this->_Myvec  = _Right._Myvec;
        this->_Mysize = _Right._Mysize;
    }

    _CONSTEXPR20_CONTAINER void _Copy_assign(const vector& _Right, true_type) {
        if (this->_Getal() == _Right._Getal()) {
            _Copy_assign(_Right, false_type{});
        } else {
            // reload proxy
            using _Alproxy_type = _Rebind_alloc_t<_Alvbase, _Container_proxy>;
            _Alproxy_type _Oldal(this->_Getal());
            _Alproxy_type _Right_proxy_al(_Right._Getal());
            _Container_proxy_ptr<_Alvbase> _Proxy(_Right_proxy_al, _Leave_proxy_unbound{});
            this->_Myvec  = _Right._Myvec;
            this->_Mysize = _Right._Mysize;
            _Proxy._Bind(_Oldal, this);
        }
    }
#endif // _ITERATOR_DEBUG_LEVEL != 0

public:
    _CONSTEXPR20_CONTAINER vector& operator=(const vector& _Right) {
        if (this != _STD addressof(_Right)) {
#if _ITERATOR_DEBUG_LEVEL == 0
            this->_Myvec  = _Right._Myvec;
            this->_Mysize = _Right._Mysize;
#else // ^^^ _ITERATOR_DEBUG_LEVEL == 0 ^^^ // vvv _ITERATOR_DEBUG_LEVEL != 0 vvv
            this->_Orphan_all();
            _Copy_assign(_Right, _Choose_pocca<_Alvbase>{});
#endif // _ITERATOR_DEBUG_LEVEL == 0
        }

        return *this;
    }

    _CONSTEXPR20_CONTAINER void reserve(_CRT_GUARDOVERFLOW size_type _Count) {
        this->_Myvec.reserve(this->_Nw(_Count));
    }

    _NODISCARD _CONSTEXPR20_CONTAINER size_type capacity() const noexcept {
        return this->_Myvec.capacity() * _VBITS;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER iterator begin() noexcept {
        return iterator(this->_Myvec.data(), this);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_iterator begin() const noexcept {
        return const_iterator(this->_Myvec.data(), this);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER iterator end() noexcept {
        return begin() + static_cast<difference_type>(this->_Mysize);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_iterator end() const noexcept {
        return begin() + static_cast<difference_type>(this->_Mysize);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_iterator cbegin() const noexcept {
        return begin();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_iterator cend() const noexcept {
        return end();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reverse_iterator crbegin() const noexcept {
        return rbegin();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reverse_iterator crend() const noexcept {
        return rend();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER iterator _Unchecked_begin() noexcept {
        return iterator(this->_Myvec.data(), this);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_iterator _Unchecked_begin() const noexcept {
        return const_iterator(this->_Myvec.data(), this);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER iterator _Unchecked_end() noexcept {
        return _Unchecked_begin() + static_cast<difference_type>(this->_Mysize);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_iterator _Unchecked_end() const noexcept {
        return _Unchecked_begin() + static_cast<difference_type>(this->_Mysize);
    }

    _CONSTEXPR20_CONTAINER void shrink_to_fit() {
        if (this->_Myvec.capacity() != this->_Myvec.size()) {
            this->_Orphan_all();
            this->_Myvec.shrink_to_fit();
        }
    }

    _CONSTEXPR20_CONTAINER iterator _Make_iter(const_iterator _Where) noexcept {
        iterator _Tmp = begin();
        if (0 < this->_Mysize) {
            _Tmp += _Where - begin();
        }

        return _Tmp;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reverse_iterator rbegin() noexcept {
        return reverse_iterator(end());
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator(end());
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reverse_iterator rend() noexcept {
        return reverse_iterator(begin());
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator(begin());
    }

    _CONSTEXPR20_CONTAINER void resize(_CRT_GUARDOVERFLOW size_type _Newsize, bool _Val = false) {
        if (size() < _Newsize) {
            _Insert_n(end(), _Newsize - size(), _Val);
        } else if (_Newsize < size()) {
            erase(begin() + static_cast<difference_type>(_Newsize), end());
        }
    }

    _NODISCARD _CONSTEXPR20_CONTAINER size_type size() const noexcept {
        return this->_Mysize;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER size_type max_size() const noexcept {
        constexpr auto _Diff_max  = static_cast<size_type>((numeric_limits<difference_type>::max)());
        const size_type _Ints_max = this->_Myvec.max_size();
        if (_Ints_max > _Diff_max / _VBITS) { // max_size bound by difference_type limits
            return _Diff_max;
        }

        // max_size bound by underlying storage limits
        return _Ints_max * _VBITS;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER bool empty() const noexcept {
        return size() == 0;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER allocator_type get_allocator() const noexcept {
        return static_cast<allocator_type>(this->_Myvec.get_allocator());
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reference at(size_type _Off) const {
        if (size() <= _Off) {
            _Xran();
        }

        return (*this)[_Off];
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reference at(size_type _Off) {
        if (size() <= _Off) {
            _Xran();
        }

        return (*this)[_Off];
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reference operator[](size_type _Off) const noexcept /* strengthened */ {
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(_Off < this->_Mysize, "vector<bool> subscript out of range");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        const_iterator _It = begin();
        _It._Advance(_Off);
        return *_It;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reference operator[](size_type _Off) noexcept /* strengthened */ {
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(_Off < this->_Mysize, "vector<bool> subscript out of range");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        iterator _It = begin();
        _It._Advance(_Off);
        return *_It;
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reference front() noexcept /* strengthened */ {
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(this->_Mysize != 0, "front() called on empty vector<bool>");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        return *begin();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reference front() const noexcept /* strengthened */ {
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(this->_Mysize != 0, "front() called on empty vector<bool>");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        return *begin();
    }

    _NODISCARD _CONSTEXPR20_CONTAINER reference back() noexcept /* strengthened */ {
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(this->_Mysize != 0, "back() called on empty vector<bool>");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        return *(end() - 1);
    }

    _NODISCARD _CONSTEXPR20_CONTAINER const_reference back() const noexcept /* strengthened */ {
#if _CONTAINER_DEBUG_LEVEL > 0
        _STL_VERIFY(this->_Mysize != 0, "back() called on empty vector<bool>");
#endif // _CONTAINER_DEBUG_LEVEL > 0

        return *(end() - 1);
    }

    _CONSTEXPR20_CONTAINER void push_back(const bool& _Val) {
        insert(end(), _Val);
    }

    _CONSTEXPR20_CONTAINER void pop_back() noexcept /* strengthened */ {
        erase(end() - 1);
    }

    template <class _Iter, enable_if_t<_Is_iterator_v<_Iter>, int> = 0>
    _CONSTEXPR20_CONTAINER void assign(_Iter _First, _Iter _Last) {
        clear();
        insert(begin(), _First, _Last);
    }

    _CONSTEXPR20_CONTAINER void assign(_CRT_GUARDOVERFLOW size_type _Count, const bool& _Val) {
        clear();
        _Insert_n(begin(), _Count, _Val);
    }

    _CONSTEXPR20_CONTAINER iterator insert(const_iterator _Where, const bool& _Val) {
        return _Insert_n(_Where, static_cast<size_type>(1), _Val);
    }

    _CONSTEXPR20_CONTAINER iterator insert(
        const_iterator _Where, _CRT_GUARDOVERFLOW size_type _Count, const bool& _Val) {
        return _Insert_n(_Where, _Count, _Val);
    }

    template <class _Iter, enable_if_t<_Is_iterator_v<_Iter>, int> = 0>
    _CONSTEXPR20_CONTAINER iterator insert(const_iterator _Where, _Iter _First, _Iter _Last) {
        difference_type _Off = _Where - begin();
        _Insert(_Where, _First, _Last, _Iter_cat_t<_Iter>{});
        return begin() + _Off;
    }

    template <class _Iter>
    _CONSTEXPR20_CONTAINER void _Insert(const_iterator _Where, _Iter _First, _Iter _Last, input_iterator_tag) {
        difference_type _Off = _Where - begin();

        for (; _First != _Last; ++_First, (void) ++_Off) {
            insert(begin() + _Off, *_First);
        }
    }

    template <class _Iter>
    _CONSTEXPR20_CONTAINER void _Insert(const_iterator _Where, _Iter _First, _Iter _Last, forward_iterator_tag) {
        _Adl_verify_range(_First, _Last);
        auto _Count    = _Convert_size<size_type>(static_cast<size_t>(_STD distance(_First, _Last)));
        size_type _Off = _Insert_x(_Where, _Count);
        _Copy_unchecked(_Get_unwrapped(_First), _Get_unwrapped(_Last), begin() + static_cast<difference_type>(_Off));
    }

    _CONSTEXPR20_CONTAINER iterator erase(const_iterator _Where_arg) noexcept /* strengthened */ {
        iterator _Where      = _Make_iter(_Where_arg);
        difference_type _Off = _Where - begin();

#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(end() > _Where, "vector<bool> erase iterator outside range");
        _STD copy(_Next_iter(_Where), end(), _Where);
        _Orphan_range(static_cast<size_type>(_Off), this->_Mysize);

#else // _ITERATOR_DEBUG_LEVEL == 2
        _STD copy(_Next_iter(_Where), end(), _Where);
#endif // _ITERATOR_DEBUG_LEVEL == 2

        _Trim(this->_Mysize - 1);
        return begin() + _Off;
    }

    _CONSTEXPR20_CONTAINER iterator erase(const_iterator _First_arg, const_iterator _Last_arg) noexcept
    /* strengthened */ {
        iterator _First      = _Make_iter(_First_arg);
        iterator _Last       = _Make_iter(_Last_arg);
        difference_type _Off = _First - begin();

        if (_First != _Last) { // worth doing, copy down over hole
#if _ITERATOR_DEBUG_LEVEL == 2
            _STL_VERIFY(_Last >= _First && end() >= _Last, "vector<bool> erase iterator outside range");
            iterator _Next      = _STD copy(_Last, end(), _First);
            const auto _Newsize = static_cast<size_type>(_Next - begin());
            _Orphan_range(_Newsize, this->_Mysize);
            _Trim(_Newsize);

#else // _ITERATOR_DEBUG_LEVEL == 2
            iterator _Next = _STD copy(_Last, end(), _First);
            _Trim(static_cast<size_type>(_Next - begin()));
#endif // _ITERATOR_DEBUG_LEVEL == 2
        }
        return begin() + _Off;
    }

    _CONSTEXPR20_CONTAINER void clear() noexcept {
        this->_Orphan_all();
        this->_Myvec.clear();
        this->_Mysize = 0;
    }

    _CONSTEXPR20_CONTAINER void flip() noexcept { // toggle all elements
        for (auto& _Elem : this->_Myvec) {
            _Elem = ~_Elem;
        }

        _Trim(this->_Mysize);
    }

    _CONSTEXPR20_CONTAINER void swap(vector& _Right) noexcept /* strengthened */ {
        if (this != _STD addressof(_Right)) {
            this->_Swap_proxy_and_iterators(_Right);
            this->_Myvec.swap(_Right._Myvec);
            _STD swap(this->_Mysize, _Right._Mysize);
        }
    }

    static _CONSTEXPR20_CONTAINER void swap(reference _Left, reference _Right) noexcept {
        bool _Val = _Left; // NOT _STD swap
        _Left     = _Right;
        _Right    = _Val;
    }

    friend hash<vector<bool, _Alloc>>;

    _CONSTEXPR20_CONTAINER iterator _Insert_n(const_iterator _Where, size_type _Count, const bool& _Val) {
        size_type _Off     = _Insert_x(_Where, _Count);
        const auto _Result = begin() + static_cast<difference_type>(_Off);
        _STD fill(_Result, _Result + static_cast<difference_type>(_Count), _Val);
        return _Result;
    }

    _CONSTEXPR20_CONTAINER size_type _Insert_x(const_iterator _Where, size_type _Count) {
        difference_type _Off = _Where - begin();

#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(end() >= _Where, "vector<bool> insert iterator outside range");
        bool _Realloc = capacity() - size() < _Count;
#endif // _ITERATOR_DEBUG_LEVEL == 2

        if (_Count != 0) {
            if (max_size() - size() < _Count) {
                _Xlen(); // result too long
            }

            // worth doing
            this->_Myvec.resize(this->_Nw(size() + _Count), 0);
            if (empty()) {
                this->_Mysize += _Count;
            } else { // make room and copy down suffix
                iterator _Oldend = end();
                this->_Mysize += _Count;
                _STD copy_backward(begin() + _Off, _Oldend, end());
            }

#if _ITERATOR_DEBUG_LEVEL == 2
            _Orphan_range(static_cast<size_type>(_Realloc ? 0 : _Off), this->_Mysize);
#endif // _ITERATOR_DEBUG_LEVEL == 2
        }

        return static_cast<size_type>(_Off);
    }

#if _ITERATOR_DEBUG_LEVEL == 2
    _CONSTEXPR20_CONTAINER void _Orphan_range_unlocked(size_type _Offlo, size_type _Offhi) const {
        const auto _Base = this->_Myvec.data();

        _Iterator_base12** _Pnext = &this->_Myproxy->_Myfirstiter;
        while (*_Pnext) { // test offset from beginning of vector
            const auto& _Pnextiter = static_cast<const_iterator&>(**_Pnext);
            const auto _Temp       = *_Pnext; // TRANSITION, VSO-1269037
            if (!_Pnextiter._Myptr) { // orphan the iterator
                _Temp->_Myproxy = nullptr;
                *_Pnext         = _Temp->_Mynextiter;
                continue;
            }
            const auto _Off = static_cast<size_type>(_VBITS * (_Pnextiter._Myptr - _Base)) + _Pnextiter._Myoff;
            if (_Off < _Offlo || _Offhi < _Off) {
                _Pnext = &_Temp->_Mynextiter;
            } else { // orphan the iterator
                _Temp->_Myproxy = nullptr;
                *_Pnext         = _Temp->_Mynextiter;
            }
        }
    }

    void _Orphan_range_locked(size_type _Offlo, size_type _Offhi) const {
        _Lockit _Lock(_LOCK_DEBUG);
        _Orphan_range_unlocked(_Offlo, _Offhi);
    }

    _CONSTEXPR20_CONTAINER void _Orphan_range(size_type _Offlo, size_type _Offhi) const {
#ifdef __cpp_lib_constexpr_dynamic_alloc
        if (_STD is_constant_evaluated()) {
            _Orphan_range_unlocked(_Offlo, _Offhi);
        } else
#endif // __cpp_lib_constexpr_dynamic_alloc
        {
            _Orphan_range_locked(_Offlo, _Offhi);
        }
    }
#endif // _ITERATOR_DEBUG_LEVEL == 2

    _CONSTEXPR20_CONTAINER void _Trim(size_type _Size) {
        if (max_size() < _Size) {
            _Xlen(); // result too long
        }

        const size_type _Words = this->_Nw(_Size);
        if (_Words < this->_Myvec.size()) {
            this->_Myvec.erase(this->_Myvec.begin() + static_cast<difference_type>(_Words), this->_Myvec.end());
        }

        this->_Mysize = _Size;
        _Size %= _VBITS;
        if (0 < _Size) {
            this->_Myvec[_Words - 1] &= (static_cast<_Vbase>(1) << _Size) - 1;
        }
    }

    [[noreturn]] void _Xlen() const {
        _Xlength_error("vector<bool> too long");
    }

    [[noreturn]] void _Xran() const {
        _Xout_of_range("invalid vector<bool> subscript");
    }
};

// STRUCT TEMPLATE SPECIALIZATION hash
template <class _Alloc>
struct hash<vector<bool, _Alloc>> {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef vector<bool, _Alloc> _ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef size_t _RESULT_TYPE_NAME;

    _NODISCARD size_t operator()(const vector<bool, _Alloc>& _Keyval) const noexcept {
        return _Hash_array_representation(_Keyval._Myvec.data(), _Keyval._Myvec.size());
    }
};

#if _HAS_CXX17
namespace pmr {
    template <class _Ty>
    using vector = _STD vector<_Ty, polymorphic_allocator<_Ty>>;
} // namespace pmr
#endif // _HAS_CXX17

// VARIABLE TEMPLATE _Is_vb_iterator
template <class _Alloc, bool _RequiresMutable>
_INLINE_VAR constexpr bool _Is_vb_iterator<_Vb_iterator<_Alloc>, _RequiresMutable> = true;

template <class _Alloc>
_INLINE_VAR constexpr bool _Is_vb_iterator<_Vb_const_iterator<_Alloc>, false> = true;

template <class _FwdIt, class _Ty>
_CONSTEXPR20 void _Fill_vbool(_FwdIt _First, _FwdIt _Last, const _Ty& _Val) {
    // Set [_First, _Last) to _Val
    if (_First == _Last) {
        return;
    }

    _Vbase* _VbFirst      = const_cast<_Vbase*>(_First._Myptr);
    _Vbase* const _VbLast = const_cast<_Vbase*>(_Last._Myptr);

    const auto _FirstSourceMask = static_cast<_Vbase>(-1) << _First._Myoff;
    const auto _FirstDestMask   = ~_FirstSourceMask;
    const auto _FillVal         = static_cast<_Vbase>(_Val ? -1 : 0);

    if (_VbFirst == _VbLast) {
        // We already excluded _First == _Last, so here _Last._Myoff > 0 and the shift is safe
        const auto _LastSourceMask = static_cast<_Vbase>(-1) >> (_VBITS - _Last._Myoff);
        const auto _LastDestMask   = ~_LastSourceMask;
        const auto _SourceMask     = _FirstSourceMask & _LastSourceMask;
        const auto _DestMask       = _FirstDestMask | _LastDestMask;
        *_VbFirst                  = (*_VbFirst & _DestMask) | (_FillVal & _SourceMask);
        return;
    }

    *_VbFirst = (*_VbFirst & _FirstDestMask) | (_FillVal & _FirstSourceMask);
    ++_VbFirst;

#ifdef __cpp_lib_constexpr_dynamic_alloc
    if (_STD is_constant_evaluated()) {
        for (; _VbFirst != _VbLast; ++_VbFirst) {
            *_VbFirst = _FillVal;
        }
    } else
#endif // __cpp_lib_constexpr_dynamic_alloc
    {
        const auto _VbFirst_ch = reinterpret_cast<const char*>(_VbFirst);
        const auto _VbLast_ch  = reinterpret_cast<const char*>(_VbLast);
        const auto _Count_ch   = static_cast<size_t>(_VbLast_ch - _VbFirst_ch);
        const auto _ValChar    = static_cast<unsigned char>(_Val ? -1 : 0);
        _CSTD memset(_VbFirst, _ValChar, _Count_ch);
        _VbFirst = _VbLast;
    }

    if (_Last._Myoff != 0) {
        const auto _LastSourceMask = static_cast<_Vbase>(-1) >> (_VBITS - _Last._Myoff);
        const auto _LastDestMask   = ~_LastSourceMask;
        *_VbFirst                  = (*_VbFirst & _LastDestMask) | (_FillVal & _LastSourceMask);
    }
}
_STD_END

#pragma pop_macro("new")
_STL_RESTORE_CLANG_WARNINGS
#pragma warning(pop)
#pragma pack(pop)
#endif // _STL_COMPILER_PREPROCESSOR
#endif // _VECTOR_
