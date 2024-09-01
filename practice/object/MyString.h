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
