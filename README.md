# Executando o projeto

## Requisitos

- **Sistema operacional:**

Linux 64 bits

- **LLVM e Clang**

Possuir LLVM e clang instalados. Exemplo para Ubuntu e derivados:

```sh
sudo apt install llvm clang
```

- **Python**

Possuir o Python 3.10 ou superior.

- **Biblioteca llvmlite**

Instalar a biblioteca llvmlite para Python.

```sh
pip install llvmlite
```

- **C++ e C**

Possuir as bibliotecas necessárias para compilação e execução de arquivos C e C++.

- **cmake**

Possuir o cmake instalado. Exemplo para Ubuntu e derivados:

```sh
sudo apt install cmake
```

- **Biblioteca googletest**

Clonar a biblioteca googletest para a pasta test do projeto.

```sh
git clone https://github.com/google/googletest.git
```

## Executando o example_max3.cpp

1. Na raiz do projeto executar o arquivo generate_max3.py, gerando assim o arquivo bitcode max3.bc e texto max3.ll

```sh
python3 generate_max3.py
```

2. Compilar o bitcode para objeto na pasta test

```sh
llc -filetype=obj max3.bc -o test/max3.o
```

3. Ir até a pasta test

```sh
cd test
```

4. Compilar e linkar

```sh
clang example_max3.cpp max3.o -o example
```

5. Executar example

```sh
./example
```


## Executando os testes

1. Na raiz do projeto executar o arquivo generate_max3.py, gerando assim o arquivo bitcode max3.bc e texto max3.ll

```sh
python3 generate_max3.py
```

2. Compilar o bitcode para objeto na pasta test

```sh
llc -filetype=obj max3.bc -o test/max3.o
```

3. Ir até a pasta test/build

```sh
cd test/build
```

4. Gerar os arquivos de build

```sh
cmake ..
```

5. Compilar o projeto

```sh
cmake --build .
```

6. Executar os testes da biblioteca

```sh
./testMax3
```