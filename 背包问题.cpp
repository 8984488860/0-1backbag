#include <iostream>  
#include <vector>  
  
using namespace std;  
  
class PackBackTrack  
{   
protected:  
    vector<int> m_p; //N����Ʒ�ļ۸�  
    vector<int> m_w; //N����Ʒ������  
    int         m_c; //������  
    int         m_num; //��Ʒ�ļ���  
    int         bestValue;          //��������ֵ  
    int         currentValue;       //��ǰ��������Ʒ�ļ�ֵ  
    int         currentWeight;      //��ǰ��������Ʒ������  
  
private:  
    //�������������ڻ�������  
    void BackTrack(int depth)  
    {  
        if(depth >= m_num)    //�ﵽ������  
        {  
            if(bestValue < currentValue)  //�������Ž�  
                bestValue = currentValue;  
            return ;  
        }  
  
        if(currentWeight +m_w[depth] <= m_c)  //�Ƿ�����Լ������  
        {  
            currentWeight += m_w[depth];  
            currentValue += m_p[depth];  
              
            //ѡȡ�˵�i����Ʒ  
            BackTrack(depth+1); //�ݹ������һ�����  
              
            //�ָ������������ͼ�ֵ  
            currentWeight -= m_w[depth];  
            currentValue  -= m_p[depth];  
        }   
        //��ȡ��i����Ʒ  
        BackTrack(depth+1);  
    }  
  
public:  
    //���캯��  
    PackBackTrack();  
    PackBackTrack(vector<int>& p,vector<int>& w, int c,int n)  
        :m_p(p),m_w(w),m_c(c),m_num(n)  
    {  
        bestValue =0;  
        currentValue =0;  
        currentWeight =0;  
    }  
  
    //��ȡ��������Ʒ�����ֵ  
    int GetBestValue()  
    {  
        BackTrack(0);  
        return bestValue;  
    }  
};  
  
  
int main(void)  
{  
    //���Գ���  
    int n;  
    int c;  
  
    cout << "��������Ʒ�ļ���" << endl;  
    cin >>n;  
    cout << "�����뱳��������" << endl;  
    cin >>c;  
    vector<int> w(n);  
    vector<int> p(n);  
  
    cout << "��������Ʒ������:" << endl;  
    for(int i=0;i<n;++i)  
        cin >> w[i];  
    cout << "��������Ʒ�ļ۸�:" << endl;  
    for(int j=0;j<n;++j)  
        cin >> p[j];
  
    PackBackTrack pack(p,w,c,n);  
  
    int bestValue = pack.GetBestValue();  
  
    cout << "�����ڵ���Ʒ������ֵΪ��" << bestValue << endl;  
  
    return 0;  
}  
