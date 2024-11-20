(define (problem hanoi-problem)
   (:domain hanoi)
   (:objects 
      a b c - post                    ; Tres postes: A, B, C
      d1 d2 d3 - disk                  ; Tres discos: d1 (más pequeño), d2, d3 (más grande)
   )
   
   (:init
      (on d3 a)                       ; El disco más grande (d3) está en la torre A
      (on d2 a)                       ; El disco mediano (d2) está sobre d3 en la torre A
      (on d1 a)                       ; El disco más pequeño (d1) está sobre d2 en la torre A
      (clear a)                       ; El poste A está libre
      (clear c)                       ; El poste C está libre
      (clear b)                       ; El poste B está libre
      (top d1 a)                      ; d1 es el disco superior en A
      (smaller d1 d2)                 ; d1 es más pequeño que d2
      (smaller d2 d3)                 ; d2 es más pequeño que d3
   )
   
   (:goal
      (and
         (on d3 c)                    ; El disco más grande (d3) debe estar en la torre C
         (on d2 c)                    ; El disco mediano (d2) debe estar sobre d3 en la torre C
         (on d1 c)                    ; El disco más pequeño (d1) debe estar sobre d2 en la torre C
      )
   )
)
