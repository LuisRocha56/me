(define (domain hanoi)
   (:requirements :strips)
   (:predicates 
      (clear ?p)                ; El poste ?p está libre
      (on ?d ?p)                ; El disco ?d está sobre el poste ?p
      (top ?d ?p)               ; El disco ?d es el disco superior en el poste ?p
      (smaller ?d1 ?d2)         ; El disco ?d1 es más pequeño que el disco ?d2
   )
   
   (:action move
      :parameters (?d - disk ?from - post ?to - post)
      :precondition (and
         (on ?d ?from)            ; El disco debe estar en el poste de origen
         (clear ?to)              ; El poste de destino debe estar libre
         (forall (?d2 - disk) 
            (imply (on ?d2 ?from) 
                   (smaller ?d2 ?d))))  ; El disco debe ser el más grande sobre el origen
      :effect (and
         (not (on ?d ?from))       ; El disco ya no está en el poste de origen
         (on ?d ?to)               ; El disco está sobre el poste de destino
         (clear ?from)             ; El poste de origen ahora está libre
         (not (clear ?to))         ; El poste de destino ya no está libre
         (top ?d ?to)              ; El disco es el superior en el poste de destino
         (forall (?d2 - disk) 
            (imply (on ?d2 ?from) 
                   (not (top ?d2 ?from))))  ; Ya no es el disco superior en el origen
   )

   (:action move-to-top
      :parameters (?d - disk ?from - post ?to - post)
      :precondition (and
         (on ?d ?from)            ; El disco debe estar en el poste de origen
         (clear ?to))             ; El poste de destino debe estar libre
      :effect (and
         (not (on ?d ?from))       ; El disco ya no está en el poste de origen
         (on ?d ?to)               ; El disco está sobre el poste de destino
         (clear ?from)             ; El poste de origen ahora está libre
         (not (clear ?to)))        ; El poste de destino ya no está libre
   )
)
)

