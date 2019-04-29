import Control.Monad (replicateM)

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = quicksort [y | y <- xs, y <= x] ++ [x] ++ quicksort [y | y <- xs, y > x]

lower_bound :: [Int] -> Int -> Int 
lower_bound a val 
              | val == a!!(length(left)) = length(left) 
              | otherwise = -1
              where left = [x | x <- a, x < val]


getIndexBinary :: [Int] -> [Int] -> [Int]
getIndexBinary a [] = [] 
getIndexBinary a (b:bs) = 
                 (lower_bound a b):getIndexBinary a bs


main :: IO ()
main = do
  n' <- getLine
  let n = read n'
  as <-replicateM n $ fmap ((\[s] -> (read s)) . words) getLine
  m' <- getLine 
  let m = read m'
  bs <-replicateM m $ fmap ((\[s] -> (read s)) . words) getLine
  let indexBinary = getIndexBinary (quicksort as) bs
  putStrLn $ unwords (map show indexBinary)

