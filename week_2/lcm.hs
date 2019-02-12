-- by Kirill Elagin

lcm_naive :: Int -> Int -> Integer
lcm_naive a b = minimum [ l | l <- [1 .. a' * b'], l `mod` a' == 0 && l `mod` b' == 0 ]
  where
    a' = fromIntegral a :: Integer
    b' = fromIntegral b :: Integer


gcd_euclidean :: Int -> Int -> Int
gcd_euclidean a 0 = a
gcd_euclidean a b = gcd_euclidean b (mod a b)
 


lcm_fast :: Int -> Int -> Int
lcm_fast a b = gcd*a*b
					where gcd = gcd_euclidean a b  


main :: IO ()
main = do
  [a, b] <- fmap words getLine
  print $ lcm_naive (read a) (read b)
