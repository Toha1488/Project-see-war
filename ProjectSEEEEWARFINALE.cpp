#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;




int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    cout << "Добро пожаловать в игру морской бой!!!" << endl;
    cout << "Здесь ты можеш сыграть с роботом" << endl;
    cout << "Правила игры" << endl;
    cout << "размер поля - 10 * 10\n";
    cout << "Игроки бросают жеребий выбырают кто стреляет первый,\n"
        << "Далее корабли расставлятся рамдомно и каждый игрок ходит по очереди,\n"
        << "Если игрок уничтожил корабль то он ходит ещё раз.\n"
        << "Побеждает тот кто убил 5 кораблей противника.\n"
        << "Желаю удачи!\n";
    cout << endl;

    int pole[10][10] = {};
    int pole2[10][10] = {};
    int pole_sekret[10][10] = {};
    int pos_row, pos_col;
    for (int i = 0; i < 5; i++)
    {
        do
        {
            pos_row = rand() % 10; // x
            pos_col = rand() % 10; // y

        } while (!(pole[pos_row][pos_col] != 1 &&
            pole[pos_row - 1][pos_col - 1] != 1 &&
            pole[pos_row - 1][pos_col] != 1 &&
            pole[pos_row - 1][pos_col + 1] != 1 &&
            pole[pos_row][pos_col + 1] != 1 &&
            pole[pos_row + 1][pos_col + 1] != 1 &&
            pole[pos_row + 1][pos_col] != 1 &&
            pole[pos_row + 1][pos_col - 1] != 1 &&
            pole[pos_row][pos_col - 1] != 1));

        pole[pos_row][pos_col] = 1;
    }

    for (int i = 0; i < 10; i++)
    {
        do
        {
            pos_row = rand() % 10; // x
            pos_col = rand() % 10; // y

        } while (!(pole2[pos_row][pos_col] != 1 &&
            pole2[pos_row - 1][pos_col - 1] != 1 &&
            pole2[pos_row - 1][pos_col] != 1 &&
            pole2[pos_row - 1][pos_col + 1] != 1 &&
            pole2[pos_row][pos_col + 1] != 1 &&
            pole2[pos_row + 1][pos_col + 1] != 1 &&
            pole2[pos_row + 1][pos_col] != 1 &&
            pole2[pos_row + 1][pos_col - 1] != 1 &&
            pole2[pos_row][pos_col - 1] != 1));
        pole2[pos_row][pos_col] = 1;
    }
    int shut_x, shut_y;
    bool popal = true;
    int count = 0;
    int shut_x2;
    int shut_y2;
    bool promax = true;
    int count2 = 0;

    while (true)
    {
        cout << "Твоё поле \n";
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << pole[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Поле врага \n";
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << pole_sekret[i][j] << " ";
            }
            cout << endl;
        }

        popal = true;
        while (popal)
        {
            cout << "Введите кординаты: ";
            cin >> shut_x;
            cin >> shut_y;
            if (pole_sekret[shut_x][shut_y] != 0)
                continue;
            cout << "Поле врага \n";
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (i == shut_x && j == shut_y)
                    {
                        if (pole2[shut_x][shut_y] == 1)
                        {
                            pole_sekret[i][j] = 5;
                        }
                        else
                        {
                            pole_sekret[i][j] = 2;
                            popal = false;
                        }
                    }
                    cout << pole_sekret[i][j] << " ";
                }
                cout << endl;
            }
            count = 0;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (pole_sekret[i][j] == 5) count++;
                }
            }
            if (count == 5)
            {
                cout << "Win player one";
                break;
            }
        }
        if (count == 5)
        {
            break;
        }

        promax = true;
        while (promax)
        {
            shut_x2 = rand() % 10;
            shut_y2 = rand() % 10;
            if (pole[shut_x2][shut_y2] != 0 && pole[shut_x2][shut_y2] != 1)
                continue;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (i == shut_x2 && j == shut_y2)
                    {
                        if (pole[shut_x2][shut_y2] == 1)
                        {
                            pole[i][j] = 5;
                        }
                        else
                        {
                            pole[i][j] = 2;
                            promax = false;
                        }
                    }
                }
            }
            count2 = 0;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (pole[i][j] == 5) count2++;
                }
            }
            if (count2 == 5)
            {
                cout << "Win robot";
                break;
            }
        }
        if (count2 == 5)
        {
            break;
        }

    }
}