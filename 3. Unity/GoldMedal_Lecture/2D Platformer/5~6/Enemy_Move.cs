using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy_Move : MonoBehaviour
{
    Rigidbody2D rigid;
    public int nextMove;
    Animator anim;
    SpriteRenderer spriterenderer;

    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
        spriterenderer = GetComponent<SpriteRenderer>();
        //�Լ�ȣ���Ҷ� delay�� �ְ� ������, =>Invoke�Լ��� ����.
        Invoke("Think", 5);
    }

    private void FixedUpdate()
    {
        //Move
        rigid.velocity = new Vector2( nextMove, rigid.velocity.y);  // ���� �������� �� ���Բ� § �ڵ�

        //Platform �������� ������ �ʰԲ� �ϴ� �ڵ�
        Vector2 frontVec = new Vector2(rigid.position.x + nextMove, rigid.position.y);
        Debug.DrawRay(frontVec, Vector3.down, new Color(0, 1, 0));
        RaycastHit2D rayHit = Physics2D.Raycast(frontVec, Vector3.down, 1, LayerMask.GetMask("Platform"));

        if(rayHit.collider ==null){
            Turn();
        }


    }

    void Think()
    {
        nextMove = Random.Range(-1, 2); // -1 <= ������ < 2

        anim.SetInteger("WalkSpeed", nextMove);

        if(nextMove!=0)
            spriterenderer.flipX = nextMove == 1;

        //�Լ�ȣ���Ҷ� delay�� �ְ� ������, =>Invoke�Լ��� ����.
        float nextThinkTime = Random.Range(2f, 5f);
        Invoke("Think", nextThinkTime);
    }

    void Turn()
    {
        nextMove *= -1; // �ݴ�ΰ��Բ� ó�����ִ� �ڵ�
        spriterenderer.flipX = nextMove == 1;

        CancelInvoke();
        Invoke("Think", 2);

    }
}
