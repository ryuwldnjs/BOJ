SELECT YEAR, MONTH, GENDER, COUNT(*)
FROM
    (SELECT *,YEAR(SALES_DATE) AS YEAR
            , MONTH(SALES_DATE) AS MONTH
            # , GENDER
            , COUNT(*) AS USERS
        FROM USER_INFO
        JOIN ONLINE_SALE
            USING(USER_ID)
        WHERE GENDER IS NOT NULL
        GROUP BY YEAR, MONTH, GENDER, USER_ID
        ORDER BY YEAR, MONTH, GENDER, USER_ID
        # ORDER BY USER_ID, SALES_DATE
    ) AS T
GROUP BY YEAR, MONTH, GENDER
