using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Mover : MonoBehaviour
{
    [SerializeField] float MoveSpeed = 10.0f;
    // Start is called before the first frame update
    void Start()
    {
        PrintInstructions();
    }

    // Update is called once per frame
    void Update()
    {
        MovePlayer();
    }

    void PrintInstructions()
    {
        Debug.Log("Welcome to the game");
        Debug.Log("Move your player with wasd or arrow keys");
        Debug.Log("Don't hit the walls!!");
    }

    void MovePlayer()
    {
        //��Ÿ Ÿ���� ���� �Ǹ�, ������ǻ�Ϳ� ������ǻ���� �����̸� ���ִµ� ������ �ȴ�. �ʴ� 10�����ӿ� 0.1 ���� �ָ� 1, �ʴ� 100�����ӿ� 0.01���� �ָ� 1�� �Ǿ� �����ϴ�.
        float xValue = Input.GetAxis("Horizontal") * Time.deltaTime * MoveSpeed;
        float zValue = Input.GetAxis("Vertical") * Time.deltaTime * MoveSpeed;

        transform.Translate(xValue, 0, zValue);
    }

}
