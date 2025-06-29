class vector_linked {
private:
    struct int_node {
        int value;
        int_node *next, *prev;
    };
    int_node *head, *tail;
    unsigned int size_;

public:
    vector_linked() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    ~vector_linked() {
        clear();
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        unsigned int size_ = 0;
        int_node* current =  this->head;
        while (current != nullptr) {
            size_++;
            current = current->next;
        }
        return size_;
    }

    unsigned int capacity() { // Retorna o espaço
        return size();

    } // reservado para armazenar os elementos
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0
        return 1.0;               // com o percentual da memória usada.
    }
        bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
            if (index > this->size_) {
                return false; 
            }

            if (index == 0) {
                push_front(value);
                return true;
            }
            if (index == this->size_) {
                push_back(value);
                return true;
            }

            int_node* new_node = new int_node;
            new_node->value = value;

            int_node* current = this->head;

            for (unsigned int i = 0; i < index; ++i) {
                current = current->next;
            }

            
            new_node->next = current;
            new_node->prev = current->prev;


            if (current->prev != nullptr) { 
                current->prev->next = new_node;
            }

            current->prev = new_node;

            this->size_++; 
            return true;
        }


    bool remove_at(unsigned int index) {
            if (index < this->size_){
                if(index == 0)
                    pop_front();
                else if(index == this->size_ - 1)
                    pop_back();
                else{
                    int_node* current  =  this->head;
                    for (unsigned int i = 0; i < index; i++)
                    {
                        current = current->next;
                    }
                    current->next->prev = current->prev;
                    current->prev->next = current->next;
                    delete current;
                    this->size_--;
                }
                return true;
            }
            return false;
        }

    bool is_empty() { // Retorna true se o vetor não contém elementos
        return size_==0;
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index,
        if (index >= this->size_)
        return -1;                   // −1 se índice inválido
        
        int_node* current = this->head;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        int_node* current = this->head;
        int_node* next_node = nullptr;

        while (current != nullptr) {
            next_node = current->next;
            delete current;
            current = next_node;
        
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;  
    }

    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->prev = this->tail;
        new_node->next = nullptr;

    if (this->head == nullptr) {
            this->head = new_node;
            this->tail = new_node;
            new_node->prev = nullptr;
        } else {
                this->tail->next = new_node; 
                new_node->prev = this->tail;
                this->tail = new_node;   
        }
        this->size_++;

    }
    
    void push_front(int value) {
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->prev = nullptr; 

        if (this->head == nullptr) { 
            this->head = new_node;
            this->tail = new_node;
            new_node->next = nullptr; 
        } else { 
            new_node->next = this->head;
            this->head->prev = new_node;
            this->head = new_node;
        }
        this->size_++;
    }

    bool pop_back() { // Remove um elemento do ``final'' do vetor
        if (this->tail == nullptr)
        return false;
        int_node* node_to_delete = this->tail;

        if (this->tail == this->head){
            node_to_delete = this->tail;
            this->tail = nullptr;
            this->head = nullptr;

        } else {
        node_to_delete = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        }
        delete node_to_delete;
        this->size_--;
        return true;
    }
    bool pop_front() { // Remove um elemento do ``início'' do vetor
        if (this->head == nullptr)
            return false;
        int_node* node_to_delete = this->head;
        if (this->head == this->tail){
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            node_to_delete = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
        }
        delete node_to_delete;
        this->size_--;
        return true;
    }
    int back() { // Retorna o elemento do ``final'' do vetor
        if (this->tail == nullptr)
            return -1;
        return this->tail->value;
    }
    int front() { // Retorna o elemento do ``início'' do vetor
        if (this->head == nullptr)
            return -1;
        return this->head->value;
    }
    bool remove(int value) { // Remove 'value' do vetor caso esteja presente
        int_node* current = this->head;
        while (current != nullptr) {

            if (current->value == value) {          
                if (this->head == this->tail) {
                    this->head = nullptr;
                    this->tail = nullptr;
                }

                else if (current == this->head) {
                    this->head = current->next;  
                    this->head->prev = nullptr;  
                }
                else if (current == this->tail) {
                    this->tail = current->prev; 
                    this->tail->next = nullptr; 
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                this->size_--;       
                return true;       
            }

            current = current->next;
        }
        return false;
    }



    int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente
        int_node* current = this->head;
        for (unsigned int i = 0; i < this->size_;i++){
            if (current->value == value)
                return i;
            current = current->next;
            }

        return -1;
    }

    int count(int value) { // Retorna quantas vezes value occorre no vetor
        int_node* current = this->head;
        int repeat = 0;
        while (current != nullptr) {
            if (current->value == value)
                repeat++;
            current = current->next;
        }

        return repeat;
    }
    int sum() { // Retorna a soma dos elementos do vetor
        int_node* current = this->head;
        int total = 0;
        
        while (current != nullptr) {
            total = current->value + total;
            current = current->next;
        }
        return total;
    }
