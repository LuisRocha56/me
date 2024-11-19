(define (problem strips-gripper-x-1)
   (:domain gripper-strips)
   (:objects rooma roomb ball4 ball3 ball2 ball1 left right)
   (:init 
      (room rooma)
      (room roomb)
      (ball ball4)
      (ball ball3)
      (ball ball2)
      (ball ball1)
      (at-robby rooma)               ; El robot comienza en la habitación 'rooma'
      (free left)                    ; El gripper izquierdo está libre
      (free right)                   ; El gripper derecho está libre
      (at ball4 rooma)               ; El balón 4 está en la habitación 'rooma'
      (at ball3 rooma)               ; El balón 3 está en la habitación 'rooma'
      (at ball2 rooma)               ; El balón 2 está en la habitación 'rooma'
      (at ball1 rooma)               ; El balón 1 está en la habitación 'rooma'
      (gripper left)                 ; El robot tiene un gripper izquierdo
      (gripper right))               ; El robot tiene un gripper derecho
   (:goal 
      (and 
         (at ball4 roomb)           ; El balón 4 debe estar en la habitación 'roomb'
         (at ball3 roomb)           ; El balón 3 debe estar en la habitación 'roomb'
         (at ball2 roomb)           ; El balón 2 debe estar en la habitación 'roomb'
         (at ball1 roomb)))         ; El balón 1 debe estar en la habitación 'roomb'
)