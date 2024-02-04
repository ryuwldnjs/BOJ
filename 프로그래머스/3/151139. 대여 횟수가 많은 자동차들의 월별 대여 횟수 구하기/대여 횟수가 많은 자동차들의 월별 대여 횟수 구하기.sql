# SELECT MONTH, CAR_ID, RECORDS
SELECT MONTH(START_DATE) AS MONTH, CAR_ID, COUNT(*) AS RECORDS
FROM 
    (SELECT CAR_ID
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE START_DATE BETWEEN "20220801" AND "20221031"
    GROUP BY CAR_ID
    HAVING COUNT(*) >= 5) AS T
JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY AS H
    USING (CAR_ID)
WHERE START_DATE BETWEEN "20220801" AND "20221031"
GROUP BY MONTH, CAR_ID
ORDER BY MONTH, CAR_ID DESC