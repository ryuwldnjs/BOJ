SELECT PRODUCT_ID, PRODUCT_NAME, PRICE*SUM(AMOUNT) AS TOTAL_SALES
FROM FOOD_PRODUCT
JOIN FOOD_ORDER
    USING(PRODUCT_ID)
WHERE MONTH(PRODUCE_DATE) = 5
GROUP BY PRODUCT_ID
ORDER BY TOTAL_SALES DESC, PRODUCT_ID