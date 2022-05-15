// string standard header

// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once
#ifndef _STRING_
#define _STRING_
#include <yvals_core.h>
#if _STL_COMPILER_PREPROCESSOR
#include <xstring>
// The <cctype> include below is to workaround many projects that assumed
// <string> includes it. We workaround it instead of fixing all the upstream
// projects because <cctype> is inexpensive. See VSO-663136.
#include <cctype>

#pragma pack(push, _CRT_PACKING)
#pragma warning(push, _STL_WARNING_LEVEL)
#pragma warning(disable : _STL_DISABLED_WARNINGS)
_STL_DISABLE_CLANG_WARNINGS
#pragma push_macro("new")
#undef new

_STD_BEGIN
// FUNCTION TEMPLATE getline
template <class _Elem, class _Traits, class _Alloc>
basic_istream<_Elem, _Traits>& getline(basic_istream<_Elem, _Traits>&& _Istr,
    basic_string<_Elem, _Traits, _Alloc>& _Str,
    const _Elem _Delim) { // get characters into string, discard delimiter
    using _Myis = basic_istream<_Elem, _Traits>;

    typename _Myis::iostate _State = _Myis::goodbit;
    bool _Changed                  = false;
    const typename _Myis::sentry _Ok(_Istr, true);

    if (_Ok) { // state okay, extract characters
        _TRY_IO_BEGIN
        _Str.erase();
        const typename _Traits::int_type _Metadelim = _Traits::to_int_type(_Delim);
        typename _Traits::int_type _Meta            = _Istr.rdbuf()->sgetc();

        for (;; _Meta = _Istr.rdbuf()->snextc()) {
            if (_Traits::eq_int_type(_Traits::eof(), _Meta)) { // end of file, quit
                _State |= _Myis::eofbit;
                break;
            } else if (_Traits::eq_int_type(_Meta, _Metadelim)) { // got a delimiter, discard it and quit
                _Changed = true;
                _Istr.rdbuf()->sbumpc();
                break;
            } else if (_Str.max_size() <= _Str.size()) { // string too large, quit
                _State |= _Myis::failbit;
                break;
            } else { // got a character, add it to string
                _Str += _Traits::to_char_type(_Meta);
                _Changed = true;
            }
        }
        _CATCH_IO_(_Myis, _Istr)
    }

    if (!_Changed) {
        _State |= _Myis::failbit;
    }

    _Istr.setstate(_State);
    return _Istr;
}

template <class _Elem, class _Traits, class _Alloc>
basic_istream<_Elem, _Traits>& getline(basic_istream<_Elem, _Traits>&& _Istr,
    basic_string<_Elem, _Traits, _Alloc>& _Str) { // get characters into string, discard newline
    return getline(_Istr, _Str, _Istr.widen('\n'));
}

template <class _Elem, class _Traits, class _Alloc>
basic_istream<_Elem, _Traits>& getline(basic_istream<_Elem, _Traits>& _Istr, basic_string<_Elem, _Traits, _Alloc>& _Str,
    const _Elem _Delim) { // get characters into string, discard delimiter
    return getline(_STD move(_Istr), _Str, _Delim);
}

template <class _Elem, class _Traits, class _Alloc>
basic_istream<_Elem, _Traits>& getline(basic_istream<_Elem, _Traits>& _Istr,
    basic_string<_Elem, _Traits, _Alloc>& _Str) { // get characters into string, discard newline
    return getline(_STD move(_Istr), _Str, _Istr.widen('\n'));
}

// sto* NARROW CONVERSIONS
inline int stoi(const string& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    // convert string to int
    int& _Errno_ref  = errno; // Nonzero cost, pay it once
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref      = 0;
    const long _Ans = _CSTD strtol(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoi argument");
    }

    if (_Errno_ref == ERANGE || _Ans < INT_MIN || INT_MAX < _Ans) {
        _Xout_of_range("stoi argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return static_cast<int>(_Ans);
}

inline long stol(const string& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    // convert string to long
    int& _Errno_ref  = errno; // Nonzero cost, pay it once
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref      = 0;
    const long _Ans = _CSTD strtol(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stol argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stol argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline unsigned long stoul(const string& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    // convert string to unsigned long
    int& _Errno_ref  = errno; // Nonzero cost, pay it once
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref               = 0;
    const unsigned long _Ans = _CSTD strtoul(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoul argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoul argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline long long stoll(const string& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    // convert string to long long
    int& _Errno_ref  = errno; // Nonzero cost, pay it once
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref           = 0;
    const long long _Ans = _CSTD strtoll(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoll argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoll argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline unsigned long long stoull(const string& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    // convert string to unsigned long long
    int& _Errno_ref  = errno; // Nonzero cost, pay it once
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref                    = 0;
    const unsigned long long _Ans = _CSTD strtoull(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoull argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoull argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline float stof(const string& _Str, size_t* _Idx = nullptr) { // convert string to float
    int& _Errno_ref  = errno; // Nonzero cost, pay it once
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref       = 0;
    const float _Ans = _CSTD strtof(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stof argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stof argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline double stod(const string& _Str, size_t* _Idx = nullptr) { // convert string to double
    int& _Errno_ref  = errno; // Nonzero cost, pay it once
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref        = 0;
    const double _Ans = _CSTD strtod(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stod argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stod argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline long double stold(const string& _Str, size_t* _Idx = nullptr) { // convert string to long double
    int& _Errno_ref  = errno; // Nonzero cost, pay it once
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref             = 0;
    const long double _Ans = _CSTD strtold(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stold argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stold argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

// sto* WIDE CONVERSIONS
inline int stoi(const wstring& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    // convert wstring to int
    int& _Errno_ref     = errno; // Nonzero cost, pay it once
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref      = 0;
    const long _Ans = _CSTD wcstol(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoi argument");
    }

    if (_Errno_ref == ERANGE || _Ans < INT_MIN || INT_MAX < _Ans) {
        _Xout_of_range("stoi argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return static_cast<int>(_Ans);
}

inline long stol(const wstring& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    // convert wstring to long
    int& _Errno_ref     = errno; // Nonzero cost, pay it once
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref      = 0;
    const long _Ans = _CSTD wcstol(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stol argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stol argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline unsigned long stoul(const wstring& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    // convert wstring to unsigned long
    int& _Errno_ref     = errno; // Nonzero cost, pay it once
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref               = 0;
    const unsigned long _Ans = _CSTD wcstoul(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoul argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoul argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline long long stoll(const wstring& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    // convert wstring to long long
    int& _Errno_ref     = errno; // Nonzero cost, pay it once
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref           = 0;
    const long long _Ans = _CSTD wcstoll(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoll argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoll argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline unsigned long long stoull(const wstring& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    // convert wstring to unsigned long long
    int& _Errno_ref     = errno; // Nonzero cost, pay it once
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref                    = 0;
    const unsigned long long _Ans = _CSTD wcstoull(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoull argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoull argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline float stof(const wstring& _Str, size_t* _Idx = nullptr) { // convert wstring to float
    int& _Errno_ref     = errno; // Nonzero cost, pay it once
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref       = 0;
    const float _Ans = _CSTD wcstof(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stof argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stof argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline double stod(const wstring& _Str, size_t* _Idx = nullptr) { // convert wstring to double
    int& _Errno_ref     = errno; // Nonzero cost, pay it once
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref        = 0;
    const double _Ans = _CSTD wcstod(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stod argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stod argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

inline long double stold(const wstring& _Str, size_t* _Idx = nullptr) { // convert wstring to long double
    int& _Errno_ref     = errno; // Nonzero cost, pay it once
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref             = 0;
    const long double _Ans = _CSTD wcstold(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stold argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stold argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

// HELPERS FOR to_string AND to_wstring AND operator<<(duration)
template <class _Elem, class _UTy>
_Elem* _UIntegral_to_buff(_Elem* _RNext, _UTy _UVal) { // format _UVal into buffer *ending at* _RNext
    static_assert(is_unsigned_v<_UTy>, "_UTy must be unsigned");

#ifdef _WIN64
    auto _UVal_trunc = _UVal;
#else // ^^^ _WIN64 ^^^ // vvv !_WIN64 vvv

    constexpr bool _Big_uty = sizeof(_UTy) > 4;
    if constexpr (_Big_uty) { // For 64-bit numbers, work in chunks to avoid 64-bit divisions.
        while (_UVal > 0xFFFFFFFFU) {
            auto _UVal_chunk = static_cast<unsigned long>(_UVal % 1000000000);
            _UVal /= 1000000000;

            for (int _Idx = 0; _Idx != 9; ++_Idx) {
                *--_RNext = static_cast<_Elem>('0' + _UVal_chunk % 10);
                _UVal_chunk /= 10;
            }
        }
    }

    auto _UVal_trunc = static_cast<unsigned long>(_UVal);
#endif // _WIN64

    do {
        *--_RNext = static_cast<_Elem>('0' + _UVal_trunc % 10);
        _UVal_trunc /= 10;
    } while (_UVal_trunc != 0);
    return _RNext;
}

template <class _Elem, class _Ty>
basic_string<_Elem> _Integral_to_string(const _Ty _Val) { // convert _Val to string
    static_assert(is_integral_v<_Ty>, "_Ty must be integral");
    using _UTy = make_unsigned_t<_Ty>;
    _Elem _Buff[21]; // can hold -2^63 and 2^64 - 1, plus NUL
    _Elem* const _Buff_end = _STD end(_Buff);
    _Elem* _RNext          = _Buff_end;
    const auto _UVal       = static_cast<_UTy>(_Val);
    if (_Val < 0) {
        _RNext    = _UIntegral_to_buff(_RNext, 0 - _UVal);
        *--_RNext = '-';
    } else {
        _RNext = _UIntegral_to_buff(_RNext, _UVal);
    }

    return basic_string<_Elem>(_RNext, _Buff_end);
}

// TRANSITION, CUDA - warning: pointless comparison of unsigned integer with zero
template <class _Elem, class _Ty>
basic_string<_Elem> _UIntegral_to_string(const _Ty _Val) { // convert _Val to string
    static_assert(is_integral_v<_Ty>, "_Ty must be integral");
    static_assert(is_unsigned_v<_Ty>, "_Ty must be unsigned");
    _Elem _Buff[21]; // can hold 2^64 - 1, plus NUL
    _Elem* const _Buff_end = _STD end(_Buff);
    _Elem* const _RNext    = _UIntegral_to_buff(_Buff_end, _Val);
    return basic_string<_Elem>(_RNext, _Buff_end);
}

// to_string NARROW CONVERSIONS
_NODISCARD inline string to_string(int _Val) { // convert int to string
    return _Integral_to_string<char>(_Val);
}

_NODISCARD inline string to_string(unsigned int _Val) { // convert unsigned int to string
    return _UIntegral_to_string<char>(_Val);
}

_NODISCARD inline string to_string(long _Val) { // convert long to string
    return _Integral_to_string<char>(_Val);
}

_NODISCARD inline string to_string(unsigned long _Val) { // convert unsigned long to string
    return _UIntegral_to_string<char>(_Val);
}

_NODISCARD inline string to_string(long long _Val) { // convert long long to string
    return _Integral_to_string<char>(_Val);
}

_NODISCARD inline string to_string(unsigned long long _Val) { // convert unsigned long long to string
    return _UIntegral_to_string<char>(_Val);
}

_NODISCARD inline string to_string(double _Val) { // convert double to string
    const auto _Len = static_cast<size_t>(_CSTD _scprintf("%f", _Val));
    string _Str(_Len, '\0');
    _CSTD sprintf_s(&_Str[0], _Len + 1, "%f", _Val);
    return _Str;
}

_NODISCARD inline string to_string(float _Val) { // convert float to string
    return _STD to_string(static_cast<double>(_Val));
}

_NODISCARD inline string to_string(long double _Val) { // convert long double to string
    return _STD to_string(static_cast<double>(_Val));
}

// to_wstring WIDE CONVERSIONS
_NODISCARD inline wstring to_wstring(int _Val) { // convert int to wstring
    return _Integral_to_string<wchar_t>(_Val);
}

_NODISCARD inline wstring to_wstring(unsigned int _Val) { // convert unsigned int to wstring
    return _UIntegral_to_string<wchar_t>(_Val);
}

_NODISCARD inline wstring to_wstring(long _Val) { // convert long to wstring
    return _Integral_to_string<wchar_t>(_Val);
}

_NODISCARD inline wstring to_wstring(unsigned long _Val) { // convert unsigned long to wstring
    return _UIntegral_to_string<wchar_t>(_Val);
}

_NODISCARD inline wstring to_wstring(long long _Val) { // convert long long to wstring
    return _Integral_to_string<wchar_t>(_Val);
}

_NODISCARD inline wstring to_wstring(unsigned long long _Val) { // convert unsigned long long to wstring
    return _UIntegral_to_string<wchar_t>(_Val);
}

_NODISCARD inline wstring to_wstring(double _Val) { // convert double to wstring
    const auto _Len = static_cast<size_t>(_CSTD _scwprintf(L"%f", _Val));
    wstring _Str(_Len, L'\0');
    _CSTD swprintf_s(&_Str[0], _Len + 1, L"%f", _Val);
    return _Str;
}

_NODISCARD inline wstring to_wstring(float _Val) { // convert float to wstring
    return _STD to_wstring(static_cast<double>(_Val));
}

_NODISCARD inline wstring to_wstring(long double _Val) { // convert long double to wstring
    return _STD to_wstring(static_cast<double>(_Val));
}
_STD_END

#pragma pop_macro("new")
_STL_RESTORE_CLANG_WARNINGS
#pragma warning(pop)
#pragma pack(pop)
#endif // _STL_COMPILER_PREPROCESSOR
#endif // _STRING_