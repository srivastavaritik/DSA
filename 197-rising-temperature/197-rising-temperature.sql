# Write your MySQL query statement below
SELECT W1.id AS Id
FROM Weather AS W1
JOIN Weather AS W2
ON DATEDIFF(W1.recordDate, w2.recordDate)=1
WHERE W1.temperature > W2.temperature