# Ejecutar con
# ./probar.sh tareas.c programa

codigo=$1
exe=$2

gcc -g $1 -o $2

# Puede comentar los casos para revisar qué pasa con cada uno individualmente
./$2 < testCases/case_01.in
./$2 < testCases/case_02.in
./$2 < testCases/case_03.in
# ./$2 < testCases/case_04.in

# Para guardar la salida y comparar con la respuesta
# ./$2 < testCases/case_01.in > testCases/case_01.out
# diff testCases/case_01.out testCases/case_01.ans

# Para revisar la memoria con valgrind
# valgrind --leak-check=full --track-origins=yes ./$2 < testCases/case_01.in