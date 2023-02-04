#include <cstring>  // для strlen()
#include <cassert>  // для assert()
#include <iostream> // для cout

class OurString
{
private:
    char* m_data;
    int m_length;
public:
    OurString(const char* source = "")
    {
        assert(source); // перевіряємо, чи не є source нульовим
        // Визначаємо довжину source + ще один символ для нуль-термінатора (символ завершення рядка)
        m_length = strlen(source) + 1;
        // Виділяємо достатньо пам'яті для зберігання значення, що копіюється, відповідно до довжини цього значення
        m_data = new char[m_length];
        // Копіюємо значення по символам в нашу виділену пам'ять
        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];
        // Переконуємося, що масив символів закінчується нульовим символом, щоб його можна було обробляти як рядок
        m_data[m_length - 1] = '\0';
    }

    OurString(OurString& source)
    {
        assert(source.getString());
        m_length = strlen(source.getString()) + 1;
        m_data = new char[m_length];
        for (int i = 0; i < m_length; ++i)
            m_data[i] = source.getString()[i];
        m_data[m_length - 1] = '\0';
    }

    ~OurString() // деструктор
    {
        // Звільняємо пам'ять, виділену для нашого рядка
        delete[] m_data;
    }

    char* getString() { return m_data; }
    int getLength() { return m_length; }
};
int main()
{
    OurString hello("Hello, group!");
    OurString copy = hello;

    std::cout << hello.getString() << '\n'; // тут невизначені результати
    return 0;
}

/*

До вказаного приклада додати конструктор копіювання таким чином, щоб виправити помилку повторного звільнення
уже звільненої пам’яті деструктором.

*/
