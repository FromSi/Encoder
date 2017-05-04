#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

void on(char a[100]);
void off();
void BgMenu();

int main() {
	char str[100];
	int key;
	M1:
	BgMenu();
	start:
	cout << "Enter the number [1-3] >> ";
	cin >> key;
	if (key>=1 && key<=3) {
		switch (key)
		{
		case 1:
			cout << "Write the text: ";
			cin.ignore(); 
			cin.getline(str, sizeof(str));
			on(str);
			cout << endl;
			goto M1;
			break;
		case 2:
			off();
			cout << endl;
			goto M1;
			break;
		case 3:
			return 0;
			break;
		}
	}
	else {
		cout << "Error!\n\n";
		goto start;
	}
	return 0;
}

void on(char a[100]) {
	FILE * fl1 = fopen("text.fsencoder", "w");
	char string2[100];
	for (int i = 0;i < strlen(a);i++)
		 {
			int num[100];
			num[i] = a[i];
			int SWnum = num[i];
			switch (SWnum)
			{
			case 90:
				a[i] = char(65);
				goto C1;
				break;
			case 122:
				a[i] = char(97);
				goto C1;
				break;
			case 57:
				a[i] = char(48);
				goto C1;
				break;
			case 32:
				a[i] = char(63);
				goto C1;
				break;
			default: 
				break;
			}
		 a[i] = char(num[i] + 1);
	 C1:	
		 if (i==0) { cout << "Encrypted text: "; }
		 cout <<a[i];
	}
		fputs(a, fl1);
		fclose(fl1);
	}

void off() {
	FILE * fl2 = fopen("text.fsencoder", "r"),*fl3 = fopen("text2.fsencoder", "w");
	char strFL2[100];
	if (fl2!=NULL) { 
	if(fgets(strFL2,sizeof(strFL2),fl2)!=NULL) {
		for (int i = 0;i < strlen(strFL2);i++)
		{
			int num[100];
			num[i] = strFL2[i];
			int SWnum = num[i];
			switch (SWnum)
			{
			case 65:
				strFL2[i] = char(90);
				goto C1;
				break;
			case 97:
				strFL2[i] = char(122);
				goto C1;
				break;
			case 48:
				strFL2[i] = char(57);
				goto C1;
				break;
			case 63:
				strFL2[i] = char(32);
				goto C1;
				break;
			default:
				break;
			}

			strFL2[i] = char(num[i] - 1);

		C1:	if (i == 0) { cout << "Decrypted text: "; }
			cout << strFL2[i];
			}
	}
	}
	else {
		perror("Oups"); return;
	}
	fputs(strFL2,fl3);
	fclose(fl2);fclose(fl3);
}

void BgMenu(){
	cout << "1 - Encrypt text\n";
	cout << "2 - Decrypt Text\n";
	cout << "3 - Exit\n";
}
