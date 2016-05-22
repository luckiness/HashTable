#include"HashTable.h"
void TestInsert1()
{
   HashTable<int> ht(10);
   ht.Insert1(89);
   ht.Insert1(18);
   ht.Insert1(49);
   ht.Insert1(58);
   ht.Insert1(9);
   ht.Remove(89);
   ht.print();
}

void TestInsert2()
{
   HashTable<int> ht(10);
   ht.Insert2(89);
   ht.Insert2(18);
   ht.Insert2(49);
   ht.Insert2(58);
   ht.Insert2(9);
   ht.print();
}
int main()
{
//TestInsert1();
	TestInsert2();
getchar();
return 0;
}