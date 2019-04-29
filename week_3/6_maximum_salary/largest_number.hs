-- by Kirill Elagin

import Control.Monad (replicateM)
import Debug.Trace

concat2Numbers :: Int -> Int -> Int
concat2Numbers a b = read ((show a) ++ (show b) )  


quickSortComp :: Int -> Int -> Bool
quickSortComp a b 
							| concat2Numbers a b > concat2Numbers b a = True
							| otherwise = False


quickSortCompEq :: Int -> Int -> Bool
quickSortCompEq a b 
							| concat2Numbers a b >= concat2Numbers b a = True
							| otherwise = False


quicksort :: [Int] -> [Int]
quicksort [] = []
quicksort (x:xs) = 
					quicksort [y | y <- xs,  quickSortComp y x ] ++ [x] ++ quicksort [y | y <- xs, quickSortCompEq x y] -- y > x


concatList :: [Int] -> String
concatList [] = []
concatList (x:xs) =
						show(x) ++ concatList xs


largest_number :: [Int] -> String
largest_number as = 
					let sorted = quicksort as
					in concatList sorted


main :: IO ()
main = do
  n' <- getLine
  let n = read n'
  as <-replicateM n $ fmap ((\[s] -> (read s)) . words) getLine
  putStrLn $ largest_number as ++ show (as)

