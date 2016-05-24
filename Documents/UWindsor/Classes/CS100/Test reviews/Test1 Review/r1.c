//
//  r1.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

p1 = "b"

p2 = p1 ++ p1 ++ p1

p3 xs = map (*2) xs

p4 (x:xs) = (foldr (++) []) (x:xs)

p5 x y z = x, if x < y & x < z
= y, if y < x & y < z
= z, if z < x & z < y

p6 [] = []
p6 (x:xs) = [2 * x] ++ p6 xs

p7 = p3 . p4

p8 xs = [x | x <- xs; xs >= xs!0]