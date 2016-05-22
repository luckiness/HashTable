#pragma once
#include<iostream>
using namespace  std;
enum state
{
	EMPTY,
	DELETE,
	EXITS
};
template<class K>
class HashTable
{
private:
	K* _tables;//��ϣ��
	size_t _size;//������ݴ�С
	size_t _capacity;//����
	state* _states;//״̬��
public:
	HashTable(size_t capacity=10):_tables(new K[capacity])
		                         ,_states(new state[capacity])
								 ,_size(0)
								 ,_capacity(capacity)
	{
		for(size_t i=0;i<_capacity;i++)
		{
	     _states[i]=EMPTY;
		}
	}
	//����̽�ⷨ
	bool Insert1(const K& key)
	{
	  Checkcapacity();
	  size_t index=HashFun(key);
	  size_t start=index;
	  while(_states[index]==EXITS)
	  {
		  /*if(_table[index]==key)
		  {
		   return false;
		  }*/
		  ++index;
		  if(index==_capacity)
		  {
		  index=0;
		  }

		  if(start==index)
		  {
		  return false;
		  }
	  }
	  _tables[index]=key;
	  _states[index]=EXITS;
	  ++_size;
	}

	//����̽�ⷨ
	bool Insert2(const K &key)
	{
	  Checkcapacity();
	  size_t index=HashFun(key);
	  size_t i=1;
	  while(_states[index]==EXITS)
	  {
	    if(_tables[index]==key)
		{
		  return false;
		}
		
		index=HashFun(key)+i*i;
		++i;
		index%=_capacity;
	  }
	  //ɾ�����
	  _tables[index]=key;
	  _states[index]=EXITS;
	  ++_size;

	  return true;
	}
	bool Find(const K& key)
	{
		size_t index=HashFun(key);
		size_t start=index;
		while(_states[index]!=EMPTY)
		{
			 if(_tables[index]==key)
			 {
				   if(_states[index]!=DELETE)
				   {
					 return true;
				   }
				   else
				   {
					return false;
				   }

			 }
			 ++index;
			 if(index==_capacity)
			 {
			  index=0;
			 }
			 if(index==start)
			 {
			  return false;
			 }
		}
		return false;
	}

	bool Remove(const K& key)
	{
	  size_t index=HashFun(key);
	  size_t start=index;
	  while(_states[index]!=EMPTY)
	  {
		   if(_tables[index]==key)
		   {
			_states[index]=DELETE;
			--_size;
			return true;
		   }
		   ++index;
		   if(index==_capacity)
		   {
			index=0;
		   }
		   if(index==start)
		   {
			return false;
		   }
	  }
	  return false;
	}


	~HashTable()
	{
	  if(_tables!=NULL)
	  {
	  delete _tables;
	  _tables=NULL;
	  }
	  if(_states!=NULL)
	  {
	   delete _states;
	   _states=NULL;
	  }
	}

	void Checkcapacity()
	{
	  if(_size*10/_capacity==7)
	  {
		  HashTable<K> tmp(2*_capacity);
		  for(size_t i=0;i<_capacity;i++)
		  {//���ɱ��������ݴ��ڣ������Insert���²����±�
			   if(_states[i]==EXITS)
			   {
			   tmp.Insert2(_tables[i]);
			   }
		  }
		  this->Swap(tmp);
	  }
	  
	}

	size_t HashFun(const K& key)
	{
	  return key%_capacity;
	}

	void Swap(HashTable<K>&ht)
	{
	 std::swap(_tables,ht._tables);
	 std:: swap(_states,ht._states);
	 std::swap(_capacity,ht._capacity);
	 std::swap(_size,ht._size);
	}

	void print()
	{
	  for(size_t i=0;i<_capacity;i++)
	  {
	  printf("[%d %d]\t",_states[i],_tables[i]);
	  }
	}

};




	
	
	