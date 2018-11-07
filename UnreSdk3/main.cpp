#include"logg.h"


extern int TEST_main();
extern int TEST_jsonExploer();
extern int TEST_dataExplorer();
extern int TEST_Ipc();
extern int TEST_register();
extern int TEST_read_write_json();
int main()
{
	TEST_register();
	return 0;

}