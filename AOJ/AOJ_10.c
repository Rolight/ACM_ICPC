#include <stdio.h>
#include <string.h>

int main()
{
	char str[2000];
	while(gets(str + 1))
	{
		int len = strlen(str + 1),i,j,k;
		for(i = len;i >= 1;i--)
		{
			//������ʱ�� ż��˳ʱ�� 
			if(i & 1)	//���� ��ʱ�� ����ķŵ�ǰ�� 
			{
				//�ѵ�һ��������Ȼ����漸����ǰ��λȻ��ѵ�һ���ŵ����
				char first = str[i];
				for(j = i;j + i <= len;j += i) str[j] = str[j + i];
				str[j] = first;
			}
			else //ż�� ˳ʱ��
			{
				//�����һ���������ŵ���һ����Ȼ��������������
				char last;
				for(j = len;j >= 1;j--) if(j % i == 0) break;
				last = str[j];
				for(;j - i >= 1;j -= i) str[j] = str[j - i];
				str[j] = last;
			} 
		}
		puts(str + 1);
	}
	return 0;
}
