-- 코드를 입력하세요
SELECT TITLE, BOARD_ID, REPLY_ID, R.WRITER_ID, R.CONTENTS,  DATE_FORMAT(R.CREATED_DATE, '%Y-%m-%d') as CREATED_DATE
from used_goods_board B
join used_goods_reply R
using(board_id)
WHERE '2022-10-31' >= B.CREATED_DATE  && B.CREATED_DATE >= '2022-10-01'
order by CREATED_DATE, TITLE