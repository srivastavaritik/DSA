# Write your MySQL query statement below
SELECT u.name , IFNULL(SUM(r.distance), 0) AS travelled_distance  
From Users u  LEFT JOIN RIDES r
ON u.id = r.user_id
GROUP BY u.id
ORDER BY travelled_distance DESC, u.name;