#include "lib.h"
//���ڰ���Щ�����ύ��git�ϣ��������
int main(void){
	char* aa[10] = { 0 };
	if (getFilesName(aa, "map", "txt", 1) == 0) {
		for (int i = 0; i < 10; i++) {
			printf("%s\n", aa[i]);
		}
	}
}