import Data.List (sortBy)

estudiantes :: [[String]]
estudiantes = [["Camilo","4.5"],["Luis","3.0"],["Sara","4.1"],["Andres","2.4"]]

comparar [nombre1,nota1] [nombre2,nota2]
    | (read nota1 :: Float) > (read nota2 :: Float) = LT
    | (read nota1 :: Float) < (read nota2 :: Float) = GT
    | otherwise = compare nombre1 nombre2
comparar _ _ = EQ

ordenados = sortBy comparar estudiantes

main = print ordenados
