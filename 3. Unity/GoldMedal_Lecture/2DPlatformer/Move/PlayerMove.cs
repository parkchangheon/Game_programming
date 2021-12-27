using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    // Start is called before the first frame update

    public float maxSpeed;
    public float jumpPower;
    Rigidbody2D rigid;
    SpriteRenderer spriteRenderer;
    Animator anim;

    private void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        spriteRenderer = GetComponent<SpriteRenderer>();
        anim = GetComponent<Animator>();
    }

    private void Update()  // �ܹ����� update
    {

        //Jump
        if(Input.GetButtonDown("Jump")&& !anim.GetBool("IsJumping"))
        {
            rigid.AddForce(Vector2.up * jumpPower, ForceMode2D.Impulse);
            anim.SetBool("IsJumping", true);
        }


        //stop speed
        if (Input.GetButtonUp("Horizontal"))
        {
            rigid.velocity = new Vector2(rigid.velocity.normalized.x * 0.5f, rigid.velocity.y);
        }

        if (Input.GetButtonDown("Horizontal"))  // ���� ��ȯ�� Flip�ϴ� ��.
            spriteRenderer.flipX = Input.GetAxisRaw("Horizontal") == -1;



        //Animation
        if (Mathf.Abs(rigid.velocity.x) <= 0.3f)
            anim.SetBool("IsWalking", false);

        else
            anim.SetBool("IsWalking", true);
    }


    private void FixedUpdate() //�������� update
    {
        // �ӵ� ���ϱ�
        float h = Input.GetAxis("Horizontal");
        rigid.AddForce(Vector2.right * h, ForceMode2D.Impulse); // �̰� ������ �ذ�.


        //Move By Key Control
        if (rigid.velocity.x > maxSpeed) // ���������� ���� ���
            rigid.velocity = new Vector2(maxSpeed, rigid.velocity.y);

        else if (rigid.velocity.x < -maxSpeed) // �������� ���� ���
            rigid.velocity = new Vector2(-maxSpeed, rigid.velocity.y);


        // Landing Platform
        if (rigid.velocity.y < 0)
        {
            Debug.DrawRay(rigid.position, Vector3.down, new Color(0, 1, 0));
            RaycastHit2D rayHit = Physics2D.Raycast(rigid.position, Vector3.down, 1, LayerMask.GetMask("Platform"));

            if (rayHit.collider != null) // ��� ���� �ʴٸ�
            {
                if (rayHit.distance < 0.5f)
                {
                    anim.SetBool("IsJumping", false);
                }
            }
        }


    }

    void Start()
    {
        
    }


}
