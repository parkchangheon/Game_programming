using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class movement : MonoBehaviour
{
    [SerializeField] float mainThrust = 100f;
    [SerializeField] float rotationThrust = 1f;
    [SerializeField] AudioClip mainEngine;

    [SerializeField] ParticleSystem mainEngineParticle;
    [SerializeField] ParticleSystem leftParticle;
    [SerializeField] ParticleSystem RightParticle;



    Rigidbody rb;
    AudioSource audioSource;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
        audioSource = GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        ProcessThrust();
        ProcessRotation();
    }

    void ProcessThrust()
    {
        if(Input.GetKey(KeyCode.Space))
        {
            StartThrusting();
        }

        else
        {
            StopThrusting();
        }

    }



    void StartThrusting()
    {
        rb.AddRelativeForce(Vector3.up * mainThrust * Time.deltaTime);
        if (!audioSource.isPlaying)
        {
            audioSource.PlayOneShot(mainEngine);
        }
        if (!mainEngineParticle.isPlaying)
            mainEngineParticle.Play();
    }
    void StopThrusting()
    {
        audioSource.Stop();
        mainEngineParticle.Stop();
    }


    void ProcessRotation()
    {
        if(Input.GetKey(KeyCode.A))
        {
            ApplyRotation(-rotationThrust);
            if(!leftParticle.isPlaying)
                leftParticle.Play();
        }

        else if( Input.GetKey(KeyCode.D))
        {
            ApplyRotation(rotationThrust);
            if (!RightParticle.isPlaying)
                RightParticle.Play();
        }
        else
        {
            RightParticle.Stop();
            leftParticle.Stop();
        }
    }

    void ApplyRotation(float rotationThisFrame)
    {
        rb.freezeRotation = true;  //freezing rotation so we can manually roatate
        transform.Rotate(Vector3.forward * rotationThisFrame * Time.deltaTime); 
        rb.freezeRotation = false;  // unfreezing rotation so the physics System can take over
    }

}