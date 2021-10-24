using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move_Player: MonoBehaviour // �÷��̾� ��Ʈ�� 
{
    public GameObject dashEffect;
    FoodObject foodobject;
    // ĳ���� �̵� �� �뽬 ���� ����
    public float c_speed = 5f; //ĳ���� �ӵ�
    public float d_speed = 1.4f; //�뽬 �ӵ�
    private Vector3 moveDir; // ĳ���� ���� ����
    Rigidbody2D rigid;
    bool isDashButtonDown; //�뽬 �Ǻ� bool
    float moveX = 0f;
    float moveY = 0f;

    // ĳ���� collider ó�� ���� �Լ� 
    private SpriteRenderer spriteRenderer;
    Vector3 oldDir = Vector3.zero;

    Animator animator;

    public float dashCoolTime = 0.0f;
    public float dashMax = 3.0f;


    float healTime = 0.0f;
    public GameObject healobject;
    public void SetHeal()
    {
        healTime = 0.5f;
        healobject.SetActive(true);
        healobject.transform.localScale = Vector3.one;
        healobject.transform.localPosition = new Vector3(0, 0.5f);
    }

    private void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        spriteRenderer = GetComponent<SpriteRenderer>();
        dashEffect.SetActive(false);
        TryGetComponent<Animator>(out animator);
        Fat(125);
    }

    public void Fat(int f)
    {
        animator.SetInteger("Fat", f);
    }

    private void Update()
    {
        if(healTime > 0)
        {
            healTime -= Time.deltaTime;
            healobject.transform.localScale = Vector3.Lerp(healobject.transform.localScale,Vector3.zero, Time.deltaTime);
            healobject.transform.localPosition += Vector3.up * Time.deltaTime;

            if (healTime < 0)
            {
                healobject.SetActive(false);
            }
        }


        moveX = Input.GetAxisRaw("Horizontal");
        moveY = Input.GetAxisRaw("Vertical");

        // �̵� ����
        moveDir = new Vector3(moveX, moveY).normalized;

        if (oldDir != Vector3.zero && moveDir == Vector3.zero)
        {
            animator.SetFloat("OldX", oldDir.x);
            animator.SetFloat("OldY", oldDir.y);
            oldDir = Vector3.zero;
        }
        else
            oldDir = moveDir;

        animator.SetFloat("PositionX", moveDir.x);
        animator.SetFloat("PositionY", moveDir.y);

        if (dashCoolTime >= 0)
            dashCoolTime -= Time.deltaTime;


        // �뽬 ������ ->Fixed��
        if (dashCoolTime <= 0 && Input.GetKeyDown(KeyCode.LeftShift))                     // ���� �뽬 ���ǽ� �־��ش�.
        {
            //isDashButtonDown = true;
            dashCoolTime = dashMax;

            StartCoroutine("Dash");
        }

    }

    IEnumerator Dash()
    {


        for (int i = 0; i < 10; i++)
        {
            rigid.MovePosition(transform.position + moveDir * (d_speed /3 ));

            if(i % 3 == 0)
            {
                GameObject DashEffectIns = Instantiate(dashEffect, transform.position, Quaternion.identity);
                // DashEffectIns.transform.LookAt(this.transform);

                var rot = moveDir;
                var angle = Mathf.Atan2(rot.y, rot.x) * Mathf.Rad2Deg;

                DashEffectIns.transform.rotation = Quaternion.Euler(0, 0, angle+180);
                


                DashEffectIns.SetActive(true);
            }


            yield return new WaitForSeconds(0.05f);
        }
    }


    private void FixedUpdate()
    {
        rigid.velocity = moveDir * c_speed;                            // ĳ���� ����
        moveX = 0;                                                      // ���Ͱ� �ʱ�ȭ
        moveY = 0;                                                      // ���Ͱ� �ʱ�ȭ

        if (isDashButtonDown)                                           // �뽬 �۵�
        {
            //dashEffect.SetActive(true);
            rigid.MovePosition(transform.position + moveDir * d_speed); // �뽬 ���ǵ� ��ŭ ���� position�� *

            GameObject DashEffectIns = Instantiate(dashEffect, transform.position, Quaternion.identity);
            DashEffectIns.transform.LookAt(this.transform);
            // Destroy(DashEffectIns, 0.08f);

            isDashButtonDown = false;                                   // �뽬 ���� �ʱ�ȭ
        }

    }

    // ĳ���� �� �浹 �̺�Ʈ
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "EnemyTag") // ��ũǪ��� �浹
        {
            //������ ó��
            spriteRenderer.color = new Color(1, 0, 0, 0.5f);
            gameObject.layer = 8;                                       // �������� // playerDamaged layer�� 
            Invoke("OnDamaged", 0.5f);                                  // OnDamaged �� �Ѿư��� // �����ð� 0.5��

            //��ũǪ�� �Ծ����� �� ������  �����ϰ�
            c_speed = 2f;
            Invoke("SpeedReturn", 0.5f);
            GameManager.gm.SetGuage(10); // ������ ���� �����ۿ��� �ҷ�����
        }
        
        if(collision.gameObject.tag =="Ally")                            // �ｺ Ǫ�� �浹
        {
            c_speed = 7f;
            Invoke("SpeedReturn", 0.5f);
            GameManager.gm.SetGuage(-10); // ������ ���� �����ۿ��� �ҷ�����
        }
    }



    void OnDamaged() // ������ ó�� �ް� �ٽ� ���
    {
        spriteRenderer.color = new Color(1, 1, 1, 1);
        gameObject.layer = 7; // ������������ => �ٽ� player layer�� 
    }

    void SpeedReturn() //���� �԰� ���� �ӵ��� �ٽ� ���ƿ�
    {
        c_speed = 5f;
    }

    


}
