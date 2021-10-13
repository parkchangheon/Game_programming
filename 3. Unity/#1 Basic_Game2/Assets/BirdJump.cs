using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class BirdJump : MonoBehaviour  //���������� �������̺���� ��ӹ޴´�
{

    // RigidBody�� �ҷ����� ������ ������ش� (�������� �̿��Ͽ�, ������ ����)
    Rigidbody2D rb;
    public float JumpPower; //public �� ����ϸ�, UPROPERTY ó�� �����Ϳ��� ������ ������.


    // Start is called before the first frame update
    void Start()  // �����ѹ� (�𸮾��� begin)
    {
        //Debug.Log("Start �Դϴ�");
        rb = GetComponent<Rigidbody2D>(); //Rigidbody2d��� ������Ʈ�� �����ͼ� rb�� ��ڴ�.
    }

    // Update is called once per frame
    void Update() // �� �����Ӹ��� (�𸮾��� Tick)
    {
        //Debug.Log("Update �Դϴ�");
        if (Input.GetMouseButtonDown(0)) //���콺 ��ư�� ���������� �����ؼ� ==>0�� ���콺 ���� ��ư
        {
            GetComponent<AudioSource>().Play();
            rb.velocity = Vector2.up * JumpPower; //2���� ��ǥ vector2.up�� (0,1)�� ��Ÿ����  
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)  //collider���� �浹�� ������ ���� �۾��� �϶�
    {
        SceneManager.LoadScene("GameOverScene");
    }


}
