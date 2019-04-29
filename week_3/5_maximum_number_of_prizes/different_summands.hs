-- by Kirill Elagin

get_values :: Int -> Int-> [Int]
get_values n i 
        | n > 2*i = i:get_values (n-i) (i+1)
        | otherwise = return n



optimal_summands :: Int -> [Int]
optimal_summands n = get_values n 1 -- write your code here

main :: IO ()
main = do
  n  <- getLine
  let summands = optimal_summands (read n)
  print $ length summands
  putStrLn $ unwords (map show summands)
