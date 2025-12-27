#include <iostream>
#include <cstring>

using namespace std;

/* =========================
   Clase Nodo
   ========================= */
class Nodo {
public:
    char dato;
    Nodo* next;

    Nodo(char d) {
        dato = d;
        next = nullptr;
    }
};

/* =========================
   Clase Pila (Stack)
   Implementada con lista enlazada
   ========================= */
class Pila {
public:
    Nodo* head;

    Pila() {
        head = nullptr;
    }

    bool pilaVacia() {
        return head == nullptr;
    }

    void push(char dato) {
        Nodo* nuevo = new Nodo(dato);
        nuevo->next = head;
        head = nuevo;
    }

    void pop() {
        if (!pilaVacia()) {
            Nodo* aux = head;
            head = head->next;
            delete aux;
        }
    }

    char top() {
        if (!pilaVacia()) {
            return head->dato;
        }
        return '\0';
    }

    char topMenosUno() {
        if (head != nullptr && head->next != nullptr) {
            return head->next->dato;
        }
        return '\0';
    }
};

/* =========================
   Prototipos
   ========================= */
bool verificarSignos(char expresion[]);
bool verificarNumeros(char expresion[]);

/* =========================
   Función principal
   ========================= */
int main() {
    char expresion[50];

    cout << "Ingrese la expresion matematica: ";
    cin >> expresion;

    bool signosValidos = verificarSignos(expresion);
    bool numerosValidos = verificarNumeros(expresion);

    if (signosValidos && numerosValidos) {
        cout << "\nOperacion valida\n";
    } else {
        cout << "\nOperacion invalida\n";
    }

    return 0;
}

/* =========================
   Verifica paréntesis, llaves y corchetes
   ========================= */
bool verificarSignos(char expresion[]) {
    Pila pila;

    for (int i = 0; i < strlen(expresion); i++) {
        char c = expresion[i];

        if (c == '(' || c == '{' || c == '[') {
            pila.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (pila.pilaVacia()) {
                return false;
            }

            char top = pila.top();

            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                pila.pop();
            } else {
                return false;
            }
        }
    }

    return pila.pilaVacia();
}

/* =========================
   Verifica que no haya números
   de más de un dígito
   ========================= */
bool verificarNumeros(char expresion[]) {
    int contador = 0;

    for (int i = 0; i < strlen(expresion); i++) {
        char c = expresion[i];

        if (c >= '0' && c <= '9') {
            contador++;
            if (contador > 1) {
                return false;
            }
        } else {
            contador = 0;
        }
    }

    return true;
}
