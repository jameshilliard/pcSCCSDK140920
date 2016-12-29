#pragma  once

#include <string>

#ifdef _WIN32
#ifndef AFX_EXT_CLASS
#  ifdef EXPORTDECL_EXPORTS
#    define AFX_EXT_CLASS __declspec(dllexport)
#  else
#    define AFX_EXT_CLASS __declspec(dllimport)
#  endif
#endif
#else
#define AFX_EXT_CLASS
#endif

class AFX_EXT_CLASS HKChameleon 
{
public:
	HKChameleon() {};
	virtual ~HKChameleon(){};
	/*explicit*/ HKChameleon(const std::string&);
	/*explicit*/ HKChameleon(double);
	/*explicit*/ HKChameleon(const char*);

	HKChameleon(const HKChameleon&);
	HKChameleon& operator=(HKChameleon const&);

	HKChameleon& operator=(double);
	HKChameleon& operator=(std::string const&);
	HKChameleon& operator=(int);
	HKChameleon& operator=(unsigned int);
	HKChameleon& operator=(bool);
	HKChameleon& operator=(unsigned short);
	HKChameleon& operator=(unsigned long long);
	HKChameleon& operator=(unsigned long);
	HKChameleon& operator=(long);

public:
	operator std::string			 () const;
	operator double					 () const;
	operator int					 () const;
	operator unsigned int			 () const;
	operator unsigned short			 () const;
	operator bool                    () const;
	operator unsigned long long      () const;
	operator long        			 () const;
	operator unsigned long 			 () const;

private:
	std::string value_;
	unsigned short end_;
};

