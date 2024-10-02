#pragma once
class MyString {
 public:
  // �������죺���졢�������졢ת�ƹ���
  MyString(); // ע�� ���ܻᵼ�³�Ա����û�г�ʼ����Ҫ����

  MyString(const MyString& ob);
  MyString(const char* ch);
  explicit MyString(size_t len); // ��ֹ��ʽת��
  MyString(MyString&& ob);

  // ������ֵ�� ��ֵ������ת�Ƹ�ֵ
  MyString& operator=(const MyString& ob);
  MyString& operator=(MyString&& ob); // ��ֵ���ܼ�const

  // һ�������� ��������
  virtual ~MyString(); // �������౻�̳� ��ô����͸����ĳЩ��Ա�����ṹ���ܲ�һ�¡�
                       // ����д����ģ�����ʵ�ֶ�̬����ô����ʱ�Ϳ��Ը����ͷ��Լ�����Դ��

  private:
   char* m_ch = nullptr;
   size_t m_len = 0;
   size_t m_alloc = 0;
};

// RVO
/*
  ���ں�������ֵ��
    1. ֵ����
    2. ���ô��� �ڲ��Բ�������

  ������ʱ����Ĵ���
    

  �������Է���ֵ���Ż���
  1. move����
  2. RVO �� NRVO ���������� ȫ��������һ��ռ���ַ��Ȼ�󴫵ݸ������ջ



*/

class MyStringTest {
  public:
   // �������
   MyStringTest();

   MyStringTest(const char* str_ptr);

   explicit MyStringTest(int size);

   MyStringTest(const MyStringTest& ob);
   MyStringTest(MyStringTest&& ob);

   // ������ֵ
   MyStringTest& operator=(const MyStringTest& ob);
   MyStringTest& operator=(MyStringTest&& ob);


   // һ������
   virtual ~MyStringTest();

 private:
   char* my_string_ptr_ = nullptr;
   int string_len = 0;
   int malloc_len = 0;
};