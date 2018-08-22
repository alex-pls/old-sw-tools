
class CModemCheck
{
	CRegKey m_CRegKey;
	OsVersionChecker m_OSVersionCheck;
public:
	bool IsModemInstalled();
	void StartModemInstallation();
};

class CRASCheck
{
	CRegKey m_CRegKey;
	OsVersionChecker m_OSVersionCheck;
public:
	bool IsRASInstalled();
	void StartRASInstallation();
};


class SystemNetwork
 {
 private:

 public:
        SystemNetwork();
        ~SystemNetwork();

 };