INCS = -IMLX42/include
LIBDIR = -LMLX42 -L/Users/pgonzal2/.brew/Cellar/glfw/3.4/lib
LIB = -lmlx42 -ldl -lglfw

main: main.c map.c
gcc ${INCS} ${LIBDIR} ${LIB} main.c -o main

hook: hook.c
gcc ${INCS} ${LIBDIR} ${LIB} hook.c -o hook

