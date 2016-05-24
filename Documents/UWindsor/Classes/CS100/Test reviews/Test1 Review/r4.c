//
//  r4.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

p1 = "hello"

p2 = p1 ++ " " ++ p1

p3 xs = map (+3) xs

p4 = foldr (*)1

p5 x y = x, if x > y
= y, if y > x

p6 xs ys = xs, if #xs > #ys
= ys, if #ys > #xs

p7 0 = 0
p7 x = x + p7 (x-1)

p8 [] = 0
p8 (x:xs) = 1 + p8 xs

p10 xs = [ x * x | x <- xs]

p11 = map square
where square x = x * x

p12 = reverse

p13 = product