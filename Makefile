# Nazwa kompilatora
CC = gcc

# Flagi dla kompilatora - pkg-config pobiera ścieżki include GTK4
CFLAGS = $(shell pkg-config --cflags gtk4)

# Flagi do linkowania bibliotek GTK4
LIBS = $(shell pkg-config --libs gtk4)

# Plik źródłowy
SRC = main.c

# Nazwa pliku wyjściowego
OUT = myapp

# Domyślna reguła kompilacji
all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

# Reguła do czyszczenia plików binarnych
clean:
	rm -f $(OUT)
