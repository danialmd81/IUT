#include <iostream>

using namespace std;

class pizza_finder
{
private:
    /* data */
public:
    void Add_N();    // افزودن محله
    void Add_P();    // افزودن پیتزا فروشی شعبه اصلی
    void Add_Br();   // افزودن شعبه پیتزا فروشی
    void Del_Br();   // حذف شعبه پیتزا فروشی
    void List_P();   // لیست تمامی پیتزا فروشی ها ي یک محله
    void list_Brs(); // مختصات تمام ی شعب یک پیتزا فروشی
    void Near_P();   // نزدیکترین پیتزا فروشی
    void Near_Br();  // نزدیکترین شعبه پیتزا فروشی
    void Avail_P();  // تمامی پیتزا فروشی هاي قابل دسترس
    void Most_Brs(); // پر شعبه ترین پیتزا فروشی
};
