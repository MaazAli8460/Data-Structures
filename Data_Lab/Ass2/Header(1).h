#pragma once
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

//----------------------------Q1-B-----------------------------//
// 0.612 for swap of 10000 values
// 0.625 for rightshift 10000 values
//----------------------------Q2-B-----------------------------//
// For worst case of WarehouseAlgorithm the ordered tuple with
// given constraints does not exist and if r<n^2  the time 
// complexity will be O(n^2)
//-----------------------------Q1------------------------------//

template <typename T>

class ArrayBasics
{
public:
    static T findMax(T A[], int i, int j)
    {
        T MAX;
        MAX = A[i];
        i++;
        for (; i <= j; i++)
        {
            if (A[i] > MAX)
            {
                MAX = A[i];
            }
            /* code */
        }

        return MAX;
    }
    static T findMaxPos(T A[], int i, int j)
    {
        T MAX, max_pos = i;
        MAX = A[i];
        i++;
        for (; i <= j; i++)
        {
            if (A[i] > MAX)
            {
                MAX = A[i];
                max_pos = i;
            }
            /* code */
        }

        return max_pos;
    }
    static T findMin(T A[], int i, int j)
    {
        T MIN;
        MIN = A[i];
        i++;
        for (; i <= j; i++)
        {
            if (A[i] < MIN)
            {
                MIN = A[i];
            }
            /* code */
        }

        return MIN;
    }
    static T findMinPos(T A[], int i, int j)
    {
        T MIN, min_pos = i;
        MIN = A[i];
        i++;
        for (; i <= j; i++)
        {
            if (A[i] < MIN)
            {
                MIN = A[i];
                min_pos = i;
            }
            /* code */
        }

        return min_pos;
    }
    static void swap(T A[], int i, int j)
    {
        T temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    static void shiftRight(T A[], int i, int j)
    {
        T temp = A[j];
        for (; j > i; j--)
        {
            A[j] = A[j - 1];
        }
        A[i] = temp;

    }
    static void shiftLeft(T A[], int i, int j)
    {
        T temp = A[i];
        for (; i < j; i++)
        {
            A[i] = A[i + 1];
        }
        A[j] = temp;

    };
    static T* createRandomArray(int size, T min, T max)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        T* arr = new T[size];
        int val;
        for (int i = 0; i < size; i++)
        {
            do
            {
                val = rand() % max;
            } while (val < min || val>max);
            arr[i] = val;

        }
        return arr;
    }
    static T** createRandomMatrix(int rows, int cols, T min, T max)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        T** arr = new T * [rows];
        int val;
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new T[cols];
            for (int k = 0; k < cols; k++)
            {
                do
                {
                    val = rand() % max;
                } while (val < min || val>max);
                arr[i][k] = val;
            }
            /* code */
        }
        return arr;
    }
    static T* copyArray(T A[], int size)
    {
        T* arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = A[i];
        }
        return arr;
    }
    static T** copyMatrix(int** A, int rows, int cols)
    {
        T** arr = new T * [rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new T[cols];
            for (int k = 0; k < cols; k++)
            {
                arr[i][k] = A[i][k];
            }
            /* code */
        }
        return arr;
    }
    static int findInArray(T A[], T q, int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (A[i] == q)
            {
                return i;
            }
            /* code */
        }
        return -1;
    }
    static int findInSortedArray(T A[], T q, int size)
    {
        return findInArray(A, q, size);
    }
    static int findFirstInSortedArray(T A[], T q, int size)
    {
        return findInArray(A, q, size);
    }
};
template<typename T>
class ArrayUtility
{
public:
    static void maxSortWithSwap(T A[], int size)
    {
        T MAX;
        int i = 0, pos = 0;

        for (; i < size; i++)
        {
            pos = ArrayBasics<T>::findMaxPos(A, i, size - 1);
            MAX = ArrayBasics<T>::findMax(A, i, size - 1);
            ArrayBasics<T>::swap(A, i, pos);
            /* code */
        }
    }
    static void maxSortWithShiftRight(T A[], int size)
    {
        T MAX;
        int i = 0, pos = 0;

        for (; i < size; i++)
        {
            pos = ArrayBasics<T>::findMaxPos(A, i, size - 1);
            MAX = ArrayBasics<T>::findMax(A, i, size - 1);
            if (pos > i)
            {
                ArrayBasics<T>::shiftRight(A, i, pos);
                A[i] = MAX;
            }
            /* code */
        }
    }
};
//-----------------------------Q2------------------------------//
template <typename F>
class WarehouseAlgorithm
{
public:
    static F hasClosePair(F* B, int n, F r)
    {
        unsigned int x = 0;
        int temp = n / 10, left = 0;
        F sum = 0;

        for (int i = 1; i < n; i++)
        {

            x = i - left;
            if (x >= temp)
            {
                left++;
                i = left + 1;
            }
            else
            {
                if (B[i] + B[left] == r)
                {
                    cout << "\nTrue\n";
                    sum = 1;
                    break;
                }
            }
            /* code */
        }
        cout << sum;
        return sum;
    }
};

//-----------------------------Q3------------------------------//
template<typename T>
T maximizeProfit(int m, int n, T a[], T p[], T s)
{
    T** arr = new T * [n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new T[m + 1];
        for (int j = 0; j <= m; j++)
        {
            arr[i][j] = 0;
        }
    }
    int barrel_sold = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] <= j)
            {
                if (p[i - 1] + arr[i - 1][j - a[i - 1]] > arr[i - 1][j])
                {
                    arr[i][j] = p[i - 1] + arr[i - 1][j - a[i - 1]];
                }
                else
                {
                    arr[i][j] = arr[i - 1][j];
                }
            }
            /* code */
        }

        /* code */
    }
    T var = arr[n][m];
    int val1;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == var)
            {
                val1 = j;
                flag = true;
                break;
            }
            /* code */
        }
        if (flag)
        {
            break;
        }

        /* code */
    }
    val1 = m - val1;
    val1 *= s;
    var = var - val1;
    return var;

}
//--------------------Q4------------------//
template <typename G>
G makeBookingSchedules(G R[][2], int n1, G Schedule[50][3], int& m)
{
    G startmin = 0, endmax = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = i + 1; j < n1; j++)
        {
            if (R[i][0] < R[j][0])
            {
                startmin = R[i][0];
                /* code */
            }
            else
            {
                startmin = R[j][0];
            }

            if (R[i][1] > R[j][1])
            {
                endmax = R[i][1];
                /* code */
            }
            else
            {
                endmax = R[j][1];
            }

        }
    }
    //  
    G** arr = new G * [n1];
    bool* arr1 = new bool[n1];
    bool* arr2 = new bool[n1];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = false;
        arr2[i] = false;

        arr[i] = new G[endmax + 1];
        for (int j = 0; j <= endmax; j++)
        {
            arr[i][j] = 0;
            /* code */
        }

    }
    for (int i = 0; i < n1; i++)
    {
        int sp = R[i][0];
        int ep = R[i][1];
        int diff = ep - sp;
        int j = sp;
        while (diff > 0)
        {
            diff--;
            if (j == sp && j != 0)
            {
                arr[i][j] = 1;
            }
            else if (j == ep)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 1;
            }
            j++;
        }

    }

    for (int i = 0; i < n1; i++)
    {
        cout << endl;
        for (int j = 0; j <= endmax; j++)
        {
            cout << arr[i][j] << " ,";
        }
    }

    int room = 0, count = 0;
    bool scedule1 = true, temp1 = false;
    int privroom = 0;
    for (int i = 0; i <= endmax; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (arr[j][i] != 0)
            {
                arr1[j] = true;
                room++;
            }
        }
        if (room > 0 && scedule1 == true)
        {
            Schedule[count][1] = i;
            scedule1 = false;
        }
        if (i != 0)
        {
            for (int k = 0; k < n1; k++)
            {
                if (arr2[k] == arr1[k])
                {
                    temp1 = false;
                }
                else
                {
                    temp1 = true;
                    break;
                }
            }
        }
        if (privroom == room && temp1 == false)
        {
            privroom = room;
            room = 0;
            continue;
        }
        else if (i != 0 && temp1 == true && room != 0 && privroom != 0)
        {
            Schedule[count][2] = i;
            Schedule[count][0] = privroom;
            count++;
            privroom = 0;
            Schedule[count][1] = i;
            temp1 = false;
        }
        else if (room == 0 && privroom > 0)
        {
            Schedule[count][2] = i;
            Schedule[count][0] = privroom;
            count++;
            privroom = 0;
            Schedule[count][1] = i + 1;
            privroom = room;
            //newsced = true;
        }
        else if (privroom > room && i != 0 && room > 0)
        {
            Schedule[count][2] = i;
            Schedule[count][0] = privroom;
            count++;
            privroom = 0;
            Schedule[count][1] = i;
            //newsced = true;
            scedule1 = false;
        }
        else if (privroom < room && i != 0 && privroom>0)
        {
            Schedule[count][2] = i;
            Schedule[count][0] = privroom;
            count++;
            privroom = 0;
            Schedule[count][1] = i;
            scedule1 = false;
        }
        privroom = room;
        for (int k = 0; k < n1; k++)
        {
            arr2[k] = arr1[k];
            arr1[k] = false;
        }
        room = 0;
    }
    
    m = count;
    G var = 0;
    return var;
}
template<typename G>
G mergeBookingSchedules(G R1[][2], int n1, G R2[][2], int n2, G mergedSchedule[50][3], int& m)
{
    int temp = n1 + n2, t1 = 0,t2=0;
    G R[50][2];
    for (int i = 0; i < n1; i++)
    {
        R[i][0] = R1[i][0];
        R[i][1] = R1[i][1];

    }
    cout<<endl<<n1<<endl<<n2<<endl<<temp<<endl;
    for (int i = n1; i < temp; i++)
    {
        R[i][0] = R2[t2][0];
        R[i][1] = R2[t2][1];
        t2++;
    }for (int i = 0; i < temp; i++)
    {
        cout <<endl<< "(" << R[i][0] << "," << R[i][1] << ")\n";
    }
    makeBookingSchedules<G>(R, temp, mergedSchedule, m);
    G var = m;
    for (int i = 0; i < m; i++) {
        cout << endl<<"(";
        for (int j = 0; j < 3; j++) {
            cout<<mergedSchedule[i][j]<<" , ";
        }
    }
    return var;

}
