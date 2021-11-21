using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move_Player: MonoBehaviour
{
    // ĳ���� �̵� �� �뽬 ���� ����
    public float c_speed = 5f; //ĳ���� �ӵ�
    public float d_speed = 1.4f; //�뽬 �ӵ�
    private Vector3 moveDir; // ĳ���� ���� ����
    Rigidbody2D rigid;
    bool isDashButtonDown; //�뽬 �Ǻ� bool
    bool isHorizonMove;
    float moveX = 0f;
    float moveY = 0f;

    // ĳ���� collider ó�� ���� �Լ� 
    private SpriteRenderer spriteRenderer;


    private void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        spriteRenderer = GetComponent<SpriteRenderer>();
    }

    private void Update()
    {
        // �ܼ� ����Ű (360�� �����ϰ�)

        bool hDown = Input.GetButtonDown("Horizontal"); //Ⱦ ��ư ������
        bool vDown = Input.GetButtonDown("Vertical");   //�� ��ư ������
        bool hUp = Input.GetButtonUp("Horizontal");     //Ⱦ ��ư ����
        bool vUp = Input.GetButtonUp("Vertical");       //�� ��ư ���� 

        if (Input.GetKey(KeyCode.W))
        {
            moveY = + 1f;
        }
        if (Input.GetKey(KeyCode.S))
        {
            moveY = -1f;
        }
        if (Input.GetKey(KeyCode.A))
        {
            moveX = -1f;
        }
        if (Input.GetKey(KeyCode.D))
        {
            moveX = +1f;
        }
        if (hDown || vUp)
            isHorizonMove = true; // ���� �̵� 
        else if (vDown || hUp)
            isHorizonMove = false; // ���� �̵�

        // �̵� ����


        // �뽬 ������ ->Fixed��
        if (Input.GetKeyDown(KeyCode.LeftShift)) // ���� �뽬 ���ǽ� �־��ش�.
        {
            isDashButtonDown = true;
        }
    }


    private void FixedUpdate()
    {
        moveDir = isHorizonMove ? new Vector3(moveX, 0) : new Vector3(0, moveY);
        rigid.velocity = moveDir * c_speed; // ĳ���� ����
        moveX = 0; // ���Ͱ� �ʱ�ȭ
        moveY = 0; // ���Ͱ� �ʱ�ȭ

        if (isDashButtonDown) // �뽬 �۵�
        {
            rigid.MovePosition(transform.position + moveDir * d_speed); // �뽬 ���ǵ� ��ŭ ���� position�� *
            isDashButtonDown = false; // �뽬 ���� �ʱ�ȭ
        }

    }

    // ĳ���� �� �浹 �̺�Ʈ
    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.CompareTag("EnemyTag"))
        {
            Debug.Log("�� ĳ���Ϳ� �΋H�����!!");
            StopCoroutine("OnHit");
            StartCoroutine("OnHit");
            Destroy(collision.gameObject);
        }
    }

    private IEnumerator OnHit()
    {
        spriteRenderer.color = Color.red;
        yield return new WaitForSeconds(1f);
        spriteRenderer.color = Color.white;
    }

    // ĳ���Ͱ� �ܰ躰�� ���ο� ���°�?

    private void Character_Slow()
    {

    }

}
