class vector_array {
private:
    int *data;
    unsigned int size_, capacity_;
    void increase_capacity() {
        if (capacity_ ==0){
            capacity_=8;
        } else {
            capacity_ *=2;
        }

        int *new_data = new int[capacity_];

        for (unsigned int i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
    }

public:
    vector_array() {        
        this->data = new int[8];
        this->size_ = 0;
        this->capacity_ = 8;
         // Construtor
    }
    ~vector_array() { // Destrutor
        delete[] data;
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size_;
    }
    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
        return this->capacity_;
    }
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual da
        return static_cast<double> (this->size_)/(this->capacity_);               // memória usada.
    }
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        if (index > size_) return false;
        if (size_== capacity_) increase_capacity();

        for (unsigned int i = size_; i > index; --i){
            data[i] = data[ i - 1];
        }

        data[index] = value;
        size_++;
        return true;
        
    }
    bool remove_at(unsigned int index) { // Remove elemento do índice index
       if (index >= size_) return false;

       for (unsigned int i = index; i < size_ - 1; ++i){
        data[i] = data[i + 1];
       }

       size_--;
       return true;
    }
    bool is_empty() { // Retorna true se o vetor não contém elementos
        return size_== 0;
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index,
        if (index>= size_) return -1;                   // −1 se índice inválido
        return data[index];
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        delete[] data;
        data = new int[8];
        capacity_ = 8;
        size_ = 0;
    }
    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        if (size_ == capacity_) increase_capacity();
        data[size_++] = value;
    }
    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
        insert_at(0, value);
    }
    bool pop_back() {            // Remove um elemento do ``final'' do vetor
        if(is_empty()) return false;
        size_--;
        return true;
    }
    bool pop_front() {           // Remove um elemento do ``início'' do vetor
        return remove_at(0);
    }
    int back() {                 // Retorna o elemento do ``final'' do vetor
        if (is_empty()) return -1;
        return data[size_ -1];
    }
    int front() {                // Retorna o elemento do ``início'' do vetor
        if (is_empty()) return -1;
        return data[0];
    }
    bool remove(int value) {     // Remove value do vetor caso esteja presente
        int index = find(value);
        if (index == -1) return false;
        return remove_at(index);// Deve retornar true se value foi removido
    }
    int find(int value) {        // Retorna o índice de value, −1 caso value não esteja presente
        for (unsigned int i = 0; i < size_; ++i){
            if (data[i] == value) return i;
        }
        return -1;
    }
    int count(int value) {       // Retorna quantas vezes value occorre no vetor
        int count = 0;
        for (unsigned int i = 0; i <size_; ++i){
            if (data[i] == value) count++;
        }                                           // Retorna 0 se value não estiver presente
        return count;
    }
    int sum() {                                             // Retorna a soma dos elementos do vetor
        int total = 0;
        for (unsigned int i =0; i < size_; ++i){
            total += data[i];
        }
        return total;                                           // Retorna 0 se o vetor estiver vazio
    }
