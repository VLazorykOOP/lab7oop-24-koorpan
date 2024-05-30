﻿//Task 1

#include <iostream>
#include <cstring>
using namespace std;
template<typename T>
void swapFirstMaxMin(T arr[], int size) {
    if (size <= 1) {
        return; //для того, коли масив пустий або має один елемент, то не тре робти обмін
    }
    //пошук макс та мін ел
    T max = arr[0];
    T min = arr[0];
    int idx_max = 0, idx_min = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
            idx_max = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            idx_min = i;
        }
    }
    //Обмін
    T temp = arr[idx_max];
    arr[idx_max] = arr[idx_min];
    arr[idx_min] = temp;
}
//специфікація функції-шаблон для типу const char*
template<>
void swapFirstMaxMin(const char* arr[], int size) {
    if (size <= 1) {
        return;
    }

    //пошук макс та мін ел
    const char* max = arr[0];
    const char* min = arr[0];
    int idx_max = 0, idx_min = 0;
    for (int i = 1; i < size; ++i) {
        if (strcmp(arr[i], max) > 0) {
            max = arr[i];
            idx_max = i;
        }
        if (strcmp(arr[i], min) < 0) {
            min = arr[i];
            idx_min = i;
        }
    }

    // Обмін
    const char* temp = arr[idx_max];
    arr[idx_max] = arr[idx_min];
    arr[idx_min] = temp;
}
//виведення
template<typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    setlocale(LC_CTYPE, "Ukr");
    //пр
    int intArray[] = { 5, 2, 9, 1, 7 };                                         //перший максимальний та перший мінімальний
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    cout << "Масив цілих чисел до обміну: ";
    printArray(intArray, intSize);
    swapFirstMaxMin(intArray, intSize);
    cout << "Масив цілих чисел після обміну: ";
    printArray(intArray, intSize);
    cout << endl;
    //Пр
    const char* strArray[] = { "apple", "banana", "orange", "grape", "kiwi" };  // обмін рядків відбувається за допомогою функції strcmp(),
                                                                                // яка порівнює рядки лексикографічно
    int strSize = sizeof(strArray) / sizeof(strArray[0]);
    cout << "Масив рядків до обміну: ";
    printArray(strArray, strSize);
    swapFirstMaxMin(strArray, strSize);
    cout << "Масив рядків після обміну: ";
    printArray(strArray, strSize);
    return 0;
}

//Task 2
/*
#include <iostream>
#include <cstring>
using namespace std;
template<typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

template<typename T>
int binarySearch(T arr[], int size, T key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1; //якщо ключ не знайдено
}

//специфікація функції-шаблон для типу const char*
template<>
int binarySearch(const char* arr[], int size, const char* key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int res = strcmp(arr[mid], key);

        //пошук успішний, повертаємо індекс
        if (res == 0)
            return mid;

        //якщо ключ менший, шукаємо в лівій половині
        if (res < 0)
            left = mid + 1;

        //якщо ключ більший, шукаємо в правій половині
        else
            right = mid - 1;
    }

    return -1; //якщо ключ не знайдено
}

//виведення
template<typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    setlocale(LC_CTYPE, "Ukr");
    // Приклад для масива цілих чисел
    int intArray[] = { 5, 2, 9, 1, 7 };
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    //сортування
    insertionSort(intArray, intSize);
    cout << "Масив цілих чисел: ";
    printArray(intArray, intSize);
    int intKey = 7;//ключ число
    int intResult = binarySearch(intArray, intSize, intKey);
    if (intResult != -1)
        cout << "Ключ " << intKey << " знайдено в позиції: " << intResult << endl;
    else
        cout << "Ключ " << intKey << " не знайдено." << endl;

    cout << endl;

    //Пр
    const char* strArray[] = { "apple", "banana", "orange", "grape", "kiwi" };
    int strSize = sizeof(strArray) / sizeof(strArray[0]);
    //сортування
    insertionSort(strArray, strSize);
    cout << "Масив рядків: ";
    printArray(strArray, strSize);
    const char* strKey = "orange";//ключ слово
    int strResult = binarySearch(strArray, strSize, strKey);
    if (strResult != -1)
        cout << "Ключ " << strKey << " знайдено в позиції: " << strResult << endl;
    else
        cout << "Ключ " << strKey << " не знайдено." << endl;
    return 0;
}
*/
//завдання3
/*
#include <iostream>
using namespace std;
template<typename T, int SIZE>
class Queue {
private:
    T arr[SIZE];
    int front;
    int rear;
    int itemCount;

public:
    Queue() : front(0), rear(-1), itemCount(0) {}
    //додати ел
    void enqueue(T data) {
        if (!isFull()) {
            rear = (rear + 1) % SIZE;
            arr[rear] = data;
            itemCount++;
        }
        else {
            cout << "Черга переповнена. Неможливо додати елемент: " << data << endl;
        }
    }
    //видалити ел
    T dequeue() {
        if (!isEmpty()) {
            T removedItem = arr[front];
            front = (front + 1) % SIZE;
            itemCount--;
            return removedItem;
        }
        else {
            cerr << "Черга порожня. Неможливо видалити елемент." << endl;
            return T();
        }
    }
    //перевірити чи черга порожня
    bool isEmpty() const {
        return itemCount == 0;
    }

    //перевірити чи черга переповнена
    bool isFull() const {
        return itemCount == SIZE;
    }

    //отримати кількість ел у черзі
    int size() const {
        return itemCount;
    }

    //отримати перший ел черги
    T peek() const {
        if (!isEmpty()) {
            return arr[front];
        }
        else {
            cerr << "Черга порожня." << endl;
            return T();
        }
    }
    //виведення
    void display() const {
        if (!isEmpty()) {
            int current = front;
            cout << "Елементи черги: ";
            for (int i = 0; i < itemCount; ++i) {
                cout << arr[current] << " ";
                current = (current + 1) % SIZE;
            }
            cout << endl;
        }
        else {
            cerr << "Черга порожня." << endl;
        }
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    Queue<int, 5> intQueue;
    cout << "Черга цілих чисел:" << endl;
    //додати ел у чергу
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    intQueue.enqueue(4);
    intQueue.enqueue(5);
    //вивести ел черги
    intQueue.display();
    //перевірити перший ел черги
    cout << "Перший елемент: " << intQueue.peek() << endl;
    //видалити ел
    intQueue.dequeue();
    intQueue.dequeue();
    cout << "Після видалення перших двох елементів: " << endl;
    intQueue.display();
    cout << "Кількість елементів у черзі: " << intQueue.size() << endl;
    cout << endl;
    Queue<string, 5> stringQueue;
    cout << "Черга рядків:" << endl;
    //додати ел у чергу
    stringQueue.enqueue("one");
    stringQueue.enqueue("two");
    stringQueue.enqueue("three");
    stringQueue.enqueue("four");
    stringQueue.enqueue("five");
    //вивести ел черги
    stringQueue.display();
    //перевірити перший ел черги
    cout << "Перший елемент: " << stringQueue.peek() << endl;
    //видалити ел
    stringQueue.dequeue();
    stringQueue.dequeue();
    cout << "Після видалення перших двох елементів: " << endl;
    stringQueue.display();
    cout << "Кількість елементів у черзі: " << stringQueue.size() << endl;
    return 0;
}
*/
//завдання4
/*
#include <iostream>
using namespace std;
template <typename T>
class List {
private:
    //структура ел списку
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* head; //покажчик на початок списку
    Node* tail; // покажчик на кінець списку
    int size;   // кількість ел у списку

public:
    // конструктор за замовчуванням
    List() : head(nullptr), tail(nullptr), size(0) {}
    // деструктор
    ~List() {
        clear();
    }

    // додати ел в кінець списку
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // видалити останній ел списку
    void pop_back() {
        if (!isEmpty()) {
            if (size == 1) {
                delete tail;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                current->next = nullptr;
                tail = current;
            }
            size--;
        }
    }
    //перевірити, чи список порожній
    bool isEmpty() const {
        return size == 0;
    }
    //очистити список
    void clear() {
        while (!isEmpty()) {
            pop_back();
        }
    }
    //клас ітератора
    class Iterator {
    private:
        Node* current;
    public:
        //конструктор ітератора
        Iterator(Node* node) : current(node) {}
        //переміщення ітератора на наступний елемент
        void next() {
            if (current)
                current = current->next;
        }
        //перевірка, чи ітератор дійшов до кінця списку
        bool isValid() const {
            return current != nullptr;
        }
        //отримати дані поточного елемента
        T& data() const {
            return current->data;
        }
    };

    //отримати початковий ітератор
    Iterator begin() const {
        return Iterator(head);
    }

    //отримати кінцевий ітератор
    Iterator end() const {
        return Iterator(nullptr);
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    // створення екземпляру списку
    List<int> myList;
    // додавання ел у список
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    //виведення ел списку
    cout << "Елементи списку: ";
    for (typename List<int>::Iterator it = myList.begin(); it.isValid(); it.next()) {
        cout << it.data() << " ";
    }
    cout <<endl;
    //видалення останнього ел
    myList.pop_back();
    //виведення ел списку після видалення
    cout << "Елементи списку після видалення останнього елемента зі списку: ";
    for (typename List<int>::Iterator it = myList.begin(); it.isValid(); it.next()) {
        cout << it.data() << " ";
    }
    cout << endl;
    return 0;
}*/