-- by Kirill Elagin

gcd_naive :: Int -> Int -> Int
gcd_naive a b = maximum [ d | d <- [1 .. min a b], a `mod` d == 0 && b `mod` d == 0 ]


gcd_euclidean :: Int -> Int -> Int
gcd_euclidean a 0 = a 
gcd_euclidean a b = gcd_euclidean b (mod a b) 


main :: IO ()
main = do
  [a, b] <- fmap words getLine
  print $ gcd_euclidean (read a) (read b)
