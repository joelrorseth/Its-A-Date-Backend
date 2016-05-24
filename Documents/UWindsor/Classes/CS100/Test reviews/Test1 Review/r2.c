//
//  test2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

p1 = [1, 2, 3]

p2 = p1 ++ p1

p3 = map (^2)

p4 = foldr (+)0

p5 xs ys = xs, if #xs >= #ys
= ys, if #ys > #xs

p6 [] = []
p6 (x:xs) = p6 xs ++ [x]

p7 = p4 . p3
