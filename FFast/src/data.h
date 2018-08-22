#include <vcl.h>
#include <StrUtils.hpp>


const int MAX_MACS = 255;
const int MAX_CATS = 255;

class CatData
 {

	private:

		AnsiString catname;
		long s_mat;
		long f_mat;

	public:

		CatData();
		CatData(AnsiString name, long smat, long fmat);
                void SetData(AnsiString name, long smat, long fmat);
		AnsiString GetName(void) { return catname;}
		long GetStart(void) { return s_mat;}
		long GetEnd(void) { return f_mat;}
		int SetRange(long smat, long fmat);
		bool IsRange(long value);
 };



class MacData
 {
	private:

		AnsiString macname;
		CatData **CatArray;
                int n_cat;

	public:

		MacData();
		~MacData();
		MacData(AnsiString name, int num_cat);
		int AddCat(AnsiString name, long smat, long fmat);
		int RemCat(AnsiString name);
		CatData* GetCat(AnsiString name);
		CatData* GetCat(int pos);
		AnsiString SearchMat(long value);
		void ListCat(TStrings * list);
		AnsiString GetName(void) { return macname;};
		int GetNumCat(void) { return n_cat;};

 };




class AllData
 {
	private:
		AnsiString bookname;
		MacData **MacArray;
                int n_mac;

	public:
		AllData();
		AllData(AnsiString name, int num_mac);
		~AllData();
		int AddMac(AnsiString name, int num_cat = 0);
		int RemMac(AnsiString name);
		MacData* GetMac(AnsiString name);
		MacData* GetMac(int pos);
                void ListMac(TStrings * list);
		int LoadFromFile(AnsiString filename);
		int SaveToFile(AnsiString filename);
                int ExportMacs(AnsiString filename);
       		AnsiString GetName(void) { return bookname;}
		int GetMacNumber(void) { return n_mac; };
		int GetTotCatNumber(void);

 };
