# Write your MySQL query statement below
SELECT 
	customer_id, 
	COUNT(customer_id)AS count_no_trans  # count number of VIsits by one client (must be used with GROUP BY !!!!)
FROM Visits
WHERE visit_id NOT IN (
		SELECT visit_id FROM Transactions)  # NOT IN clients that made a trans 
GROUP BY customer_id