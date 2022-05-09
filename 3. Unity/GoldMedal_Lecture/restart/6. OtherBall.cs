using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OtherBall : MonoBehaviour
{
    Rigidbody rigid;
    MeshRenderer mesh;
    Material mat;
    
    void Start()
    {
        mesh = GetComponent<MeshRenderer>();
        mat = mesh.material;
    }

    private void OnCollisionEnter(Collision collision)  //Collision �� �浹�� ������Ʈ�� ������ ������ �ִ�.
    {
        if(collision.gameObject.name == "Test") // ������Ʈ�� �̸��� �������ش�.
            mat.color = new Color(0, 0, 0);
    }


    private void OnCollisionExit(Collision collision)
    {
        mat.color = new Color(1, 1, 1);
    }

}
