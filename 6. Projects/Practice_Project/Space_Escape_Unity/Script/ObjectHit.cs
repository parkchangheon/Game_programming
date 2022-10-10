using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObjectHit : MonoBehaviour
{


    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            Debug.Log("Bump in to a Wall");
            GetComponent<MeshRenderer>().material.color = Color.red;
            gameObject.tag = "Hit"; //�±׸� Hit���� �ٲپ��ش�.
        }
        
    }
}
 