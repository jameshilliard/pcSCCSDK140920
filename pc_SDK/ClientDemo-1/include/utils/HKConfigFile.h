#pragma  once

#include <string>
#include <map>
#include "utils/HKChameleon.h"

#define CFG_LOCAL        "local"
#define CFG_IP           "ip"
#define CFG_PORT         "port"
#define CFG_USER         "user"
#define CFG_PASSWD       "Password"
#define CFG_TRUNKOUT     "trunkout"
#define CFG_DOMAIN       "domain"
#define CFG_DATABASE     "database"
#define CFG_DBHOST       "dbhost"
#define CFG_DBPORT       "dbport"
#define CFG_DBUSER       "dbuser"
#define CFG_DBPWD        "dbpassword"
#define CFG_DBNAME       "dbname"
#define CFG_ENABLE       "enable"
#define CFG_HKCODE       "HKCode"
#define CFG_HKTYPE       "HKType"
//begin Huqing 03-24 
#define CFC_RESTORE      "restore"
#define CFC_FLAG         "flag"
#define CFC_SELECTPLAN   "selectplan"
#define CFC_PLAN         "plan"
#define CFG_COMPORT      "ComPort"

#define CFG_CONIP        "HKConIP"
#define CFG_UDPCOUNT     "HKUDPConCount"
#define CFG_TCPCOUNT     "HKTCPConCount"
//end Huqing

typedef std::map<std::string,HKChameleon> MAPCHAMELEON;

class  AFX_EXT_CLASS HKConfigFile 
{
public:
	HKConfigFile(std::string const& configFile);
	virtual ~ HKConfigFile(){};

	HKChameleon const& Value(std::string const& section, std::string const& entry) const;

	HKChameleon const& Value(std::string const& section, std::string const& entry, double value);
	HKChameleon const& Value(std::string const& section, std::string const& entry, std::string const& value);
private:
	MAPCHAMELEON content_;
};

